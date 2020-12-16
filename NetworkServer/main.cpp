#include <map>
#include <set>

#include "../NetworkCommon/ThreadSafeQueue.h"
#include "../NetworkCommon/Message.h"
#include "../NetworkCommon/common.h"
#include "../NetworkCommon/RandomGenerator.h"

using asio::ip::tcp;

const int LIMIT_PER_ROOM = 2;

// USE THESE TYPEDEFS
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

// Abstract class that represents participant in the chat.
class ConnectionParticipant
{
public:
	virtual ~ConnectionParticipant() = default;

	// Delivering given message to the participant.
	virtual void deliver(const Message& msg) = 0;
};

typedef std::shared_ptr<ConnectionParticipant> participant_ptr;

// Rensposible for participant manipulation and message delivery.
class ConnectionRoom
{
public:
	bool is_full() const
	{
		return number_of_participants() == LIMIT_PER_ROOM;
	}

	void join(participant_ptr participant)
	{
		_participants.insert(participant);
	}

	void leave(participant_ptr participant)
	{
		_participants.erase(participant);
	}

	void deliver(const Message& msg)
	{
		_recent_msgs.push_back(msg);

		for (const participant_ptr& participant : _participants)
			participant->deliver(msg);
	}

	std::size_t number_of_participants() const
	{
		return _participants.size();
	}

private:
	std::set<participant_ptr> _participants;
	ThreadSafeQueue<Message> _recent_msgs;
};

typedef std::shared_ptr<ConnectionRoom> room_ptr;

// Responsible for passing requests to the ChatRoom that are received from
// participants via network.
class ConnectionSession
	: public ConnectionParticipant,
	public std::enable_shared_from_this<ConnectionSession>
{
public:
	ConnectionSession(tcp::socket socket, ConnectionRoom& room, std::map<game_t, room_ptr>& active_rooms)
		: _socket(std::move(socket))
		, _room(room)
		, _active_rooms(active_rooms)
		, _store_header()
		, _store_message()
		, _series_ptr_read(nullptr)
		, _series_ptr_write(nullptr)
	{}

	void start()
	{
		_room.join(shared_from_this());
		read_header();
	}

	void deliver(const Message& msg)
	{
		bool in_progress = !_write_msgs.empty();
		_write_msgs.push_back(msg);

		if (!in_progress)
		{
			write_header();
		}
	}

private:
	// Reads message's header from the opened socket. It's working asynchronously.
	void read_header()
	{
		_series_ptr_read.reset(new std::vector<uint8_t>(Header::get_header_size()));

		asio::async_read(_socket,
			asio::buffer(_series_ptr_read->data(), Header::get_header_size()),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					_store_header = Header(*_series_ptr_read);
					std::cout << _store_header << std::endl;

					// Reading message involves reading header first.
					read_body();
				}
				else
				{
					_room.leave(shared_from_this());
				}
			}
		);
	}

	// Parsing received message.
	// TODO: Not all cases are covered.
	void parse_message()
	{
		Communication::msg_header_t msg_id = _store_header.get_msg_id();
		owner_t owner_id = _store_header.get_owner_id();
		game_t game_id = _store_header.get_game_id();

		if (msg_id == Communication::msg_header_t::CLIENT_CREATE_GAME)
		{
			// Creating new room and responding with OK.
			_active_rooms.insert(std::make_pair(game_id, std::make_shared<ConnectionRoom>()));
			// Assigning participant to current room.
			_active_rooms[game_id]->join(shared_from_this());

			Header h(Communication::msg_header_t::SERVER_OK, owner_id, game_id);
			Message msg(h);
			_room.deliver(msg);
			_room.leave(shared_from_this());
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_JOIN_GAME)
		{
			// Searching for proper room.
			auto it_room = _active_rooms.find(game_id);

			if (it_room == _active_rooms.end() || it_room->second->is_full())
			{
				// In case such room doesn't exist responding with ERROR.
				Header h(Communication::msg_header_t::SERVER_ERROR, owner_id, game_id);
				Message msg(h);
				_room.deliver(msg);
			}
			else
			{
				// In case such room exists server responds with OK.
				Header h(Communication::msg_header_t::SERVER_OK, owner_id, game_id);
				Message msg(h);
				// Assigning participant to proper room.
				it_room->second->join(shared_from_this());
				it_room->second->deliver(msg);

				// Removing participant from current room.
				_room.leave(shared_from_this());
			}
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_CHAT)
		{
			// Sending client's message to all participants in the room.
			game_t game_id = _store_header.get_game_id();
			_store_message.get_header().set_msg_id(Communication::msg_header_t::SERVER_CHAT);
			_active_rooms[game_id]->deliver(_store_message);
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_QUIT_GAME)
		{
			// Participant has quit so server should end the game.
			game_t game_id = _store_header.get_game_id();
			Header h(Communication::msg_header_t::SERVER_END_GAME, owner_id, game_id);
			Message msg(h);
			_active_rooms[game_id]->deliver(msg);
			_room.leave(shared_from_this());
		}
	}

	// Reads message's body from the opened socket. It's working asynchronously.
	void read_body()
	{
		std::vector<uint8_t> body_series(_store_header.get_size());
		_series_ptr_read.reset(new std::vector<uint8_t>(std::move(body_series)));

		asio::async_read(_socket,
			asio::buffer(_series_ptr_read->data(), _series_ptr_read->size()),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					_store_message.set_header(_store_header);
					_store_message << *_series_ptr_read;
					Communication::msg_header_t msg_id = _store_header.get_msg_id();
					owner_t owner_id = _store_header.get_owner_id();
					game_t game_id = _store_header.get_game_id();

					// Parse message and message client properly.
					parse_message();

					// Message has been received; start reading a new one.
					read_header();
				}
				else
				{
					_room.leave(shared_from_this());
				}
			}
		);
	}

	// Writes message's header to the opened socket. It's working asynchronously.
	void write_header()
	{
		std::vector<uint8_t> header_series = _write_msgs.front().get_header().serialize();
		_series_ptr_write.reset(new std::vector<uint8_t>(std::move(header_series)));

		asio::async_write(_socket, asio::buffer(_series_ptr_write->data(), _series_ptr_write->size()),
			[this](const asio::error_code& ec, size_t)
			{
				if (!ec)
				{
					// Writing message involes writing header first.
					write_body();
				}
				else
				{
					_room.leave(shared_from_this());
				}
			}
		);
	}

	// Writes message's body to the opened socket. It's working asynchronously.
	void write_body()
	{
		std::vector<uint8_t> body_series = _write_msgs.front().serialize();
		_series_ptr_write.reset(new std::vector<uint8_t>(std::move(body_series)));

		asio::async_write(_socket, asio::buffer(_series_ptr_write->data(), _series_ptr_write->size()),
			[this](const asio::error_code& ec, size_t)
			{
				if (!ec)
				{
					// Pop written message from not-written queue.
					_write_msgs.pop_front();

					// Ff there are more messages to be written, start writing a new one.
					if (!_write_msgs.empty())
						write_header();
				}
				else
				{
					_room.leave(shared_from_this());
				}
			}
		);
	}

	// ASIO buffers point to data which don't have local scope. For that purpose smart pointers
	// are used for easier manipulation with data on heap. These poiners serve purpose of placeholders.
	std::unique_ptr<std::vector<uint8_t>> _series_ptr_write;
	std::unique_ptr<std::vector<uint8_t>> _series_ptr_read;

	tcp::socket _socket;
	ConnectionRoom& _room;
	std::map<game_t, room_ptr>& _active_rooms;

	Header _store_header;
	Message _store_message;
	ThreadSafeQueue<Message> _write_msgs;
};

class ConnectionServer
{
public:
	ConnectionServer(asio::io_context& context, const tcp::endpoint& endpoint)
		: _acceptor(context, endpoint)
	{
		accept();
	}

private:
	// Accepting new participant. Current implementation allows two players 
	void accept()
	{
		_acceptor.async_accept(
			[this](const asio::error_code& ec, tcp::socket socket)
			{
				if (!ec)
				{
					std::make_shared<ConnectionSession>(std::move(socket), _waiting_room, _active_rooms)->start();
				}

				accept();
			}
		);
	}

	tcp::acceptor _acceptor;
	ConnectionRoom _waiting_room;
	std::map<game_t, room_ptr> _active_rooms;
};

int main()
{
	// localhost
	const int port = 5000;

	// context will be shared for all participants
	asio::io_context context;

	// such initialization is used for accepting new connections
	tcp::endpoint endpoint(tcp::v4(), port);

	ConnectionServer server(context, endpoint);

	/*
	Since everything happens asynchronously we need to asign idle work
	to prevent context from closing prior to first I/O operation.
	*/
	asio::io_context::work idle_work(context);

	context.run();

	return 0;
}