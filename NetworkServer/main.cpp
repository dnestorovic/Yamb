#include <map>
#include <set>
#include <utility>

#include "../NetworkCommon/ThreadSafeQueue.h"
#include "../NetworkCommon/Message.h"
#include "../NetworkCommon/common.h"
#include "../NetworkCommon/RandomGenerator.h"

#include "../Classes/Game.h"
#include "../Classes/Player.h"
#include "../Classes/Field.h"
#include "../Classes/Column.h"
#include "../Classes/Human_player.h"
#include "../Classes/Ticket.h"

using asio::ip::tcp;

// USE THESE TYPEDEFS
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

enum class DeliverType
{
	SAME, // Send a message to the owner of the message.
	OPPOSITE, // Send a message to participants who don't own the message.
	ALL // Send a message to all participants.
};

// Abstract class that represents participant in the chat.
class ConnectionParticipant
{
public:
	virtual ~ConnectionParticipant() = default;

	// Delivering given message to the participant.
	virtual void deliver(Message& msg) = 0;

	owner_t get_owner_id() const
	{
		return _owner_id;
	}

	Player* get_player()
	{
		return _player;
	}

protected:
	Player* _player;
	owner_t _owner_id;
};

typedef std::shared_ptr<ConnectionParticipant> participant_ptr;

// Rensposible for participant manipulation and message delivery.
class ConnectionRoom
{
public:
	bool is_full() const
	{
		return number_of_participants() == ROOM_LIMIT;
	}

	void join(participant_ptr participant)
	{
		if (participant->get_player())
		{
			// This check is neccesarry because of waiting room.
			_game.add_player(participant->get_player());
		}
		_participants.insert(participant);
	}

	void leave(participant_ptr participant)
	{
		_participants.erase(participant);
	}

	void deliver(Message& msg, DeliverType d_type)
	{
		if (d_type == DeliverType::ALL)
		{
			for (const participant_ptr& participant : _participants)
				participant->deliver(msg);
		}
		else if (d_type == DeliverType::SAME)
		{
			for (const participant_ptr& participant : _participants)
			{
				if (participant->get_owner_id() == msg.get_header().get_owner_id())
					participant->deliver(msg);
			}
		}
		else if (d_type == DeliverType::OPPOSITE)
		{
			for (const participant_ptr& participant : _participants)
			{
				if (participant->get_owner_id() != msg.get_header().get_owner_id())
					participant->deliver(msg);
			}
		}
	}

	std::size_t number_of_participants() const
	{
		return _participants.size();
	}

private:
	std::set<participant_ptr> _participants;
	Game _game;
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

	void deliver(Message& msg)
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
			// Setting owner_id for the first time.
			ConnectionParticipant::_owner_id = owner_id;
			// Creating player.
			ConnectionParticipant::_player = new HumanPlayer(nullptr, nullptr, nullptr);

			// Creating new room and responding with OK.
			_active_rooms.insert(std::make_pair(game_id, std::make_shared<ConnectionRoom>()));
			// Assigning participant to current room.
			_active_rooms[game_id]->join(shared_from_this());

			Header h(Communication::msg_header_t::SERVER_OK, owner_id, game_id);
			Message msg(h);
			_room.deliver(msg, DeliverType::SAME);
			_room.leave(shared_from_this());
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_JOIN_GAME)
		{
			// Setting owner_id for the first time.
			ConnectionParticipant::_owner_id = owner_id;
			// Creating player.
			ConnectionParticipant::_player = new HumanPlayer(nullptr, nullptr, nullptr);

			// Searching for proper room.
			auto it_room = _active_rooms.find(game_id);

			if (it_room == _active_rooms.end() || it_room->second->is_full())
			{
				// In case such room doesn't exist responding with ERROR.
				Header h(Communication::msg_header_t::SERVER_ERROR, owner_id, game_id);
				Message msg(h);
				_room.deliver(msg, DeliverType::SAME);
			}
			else
			{
				// In case such room exists server responds with OK.
				Header h(Communication::msg_header_t::SERVER_OK, owner_id, game_id);
				Message msg(h);
				// Assigning participant to proper room.
				it_room->second->join(shared_from_this());
				it_room->second->deliver(msg, DeliverType::SAME);

				// Removing participant from current room.
				_room.leave(shared_from_this());

				// Opponent player shall play their move.
				msg.get_header().set_msg_id(Communication::msg_header_t::SERVER_PLAY_MOVE);
				it_room->second->deliver(msg, DeliverType::OPPOSITE);
			}
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_CHAT)
		{
			// Sending client's message to all participants in the room.
			_store_message.get_header().set_msg_id(Communication::msg_header_t::SERVER_CHAT);
			_active_rooms[game_id]->deliver(_store_message, DeliverType::ALL);
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_QUIT_GAME)
		{
			// Participant has quit so server should end the game.
			Header h(Communication::msg_header_t::SERVER_END_GAME, owner_id, game_id);
			Message msg(h);
			_active_rooms[game_id]->deliver(msg, DeliverType::OPPOSITE);
			_room.leave(shared_from_this());
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_INTERMEDIATE_MOVE)
		{
			_store_message.get_header().set_msg_id(Communication::msg_header_t::SERVER_INTERMEDIATE_MOVE);
			_active_rooms[game_id]->deliver(_store_message, DeliverType::OPPOSITE);
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_FINISH_MOVE)
		{
			// Reading which dice are selected to be played.
			std::vector<Dice> selected_dice;
			for (int i = 0; i < NUM_OF_DICE; i++)
			{
				int8_t x;
				_store_message >> x;

				if (x < 0)
				{
					selected_dice.emplace_back(-x);
				}
			}

			// Reading how many rolls till end.
			uint8_t roll_countdown;
			_store_message >> roll_countdown;

			// Note that row and col should be read in reverse order.
			uint8_t row, col;
			_store_message >> col >> row;

			// This participant is updating its ticket.
			Fields field = Field::row_to_enum(row);
			Columns column = Column::col_to_enum(col);
			bool outcome = ConnectionParticipant::_player->write_on_ticket(
				selected_dice,
				field,
				column,
				ROLLS_PER_MOVE - roll_countdown
			);

			if (outcome) 
			{
				// Move is legal and participants are properly notified.
				size_t enum_row = static_cast<size_t>(field);
				size_t enum_col = static_cast<size_t>(column);
				score_t score = static_cast<uint8_t>(ConnectionParticipant::_player->get_ticket().get_ticket_value()[enum_row][enum_col]);

				auto column_sum = ConnectionParticipant::_player->get_ticket().calculate_column_sum(column);
				score_t upper_sum = static_cast<score_t>(std::get<0>(column_sum));
				score_t middle_sum = static_cast<score_t>(std::get<1>(column_sum));
				score_t lower_sum = static_cast<score_t>(std::get<2>(column_sum));

				Header h(Communication::msg_header_t::SERVER_FINISH_MOVE, owner_id, game_id);
				Message msg(h);
				msg << row << col << score << upper_sum << middle_sum << lower_sum;
				_active_rooms[game_id]->deliver(msg, DeliverType::ALL);

			}
			else
			{
				// Move is illegal and owner is notified about it.
				Header h(Communication::msg_header_t::SERVER_ERROR, owner_id, game_id);
				Message msg(h);
				_active_rooms[game_id]->deliver(msg, DeliverType::SAME);
			}
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_ANNOUNCEMENT)
		{
			// Coordinates of the announcement field.
			uint8_t row;
			_store_message >> row;
			Fields field = Field::row_to_enum(row);

			std::cout << int(row) << std::endl;

			bool is_allowed = ConnectionParticipant::_player->announce(field);
			if (!is_allowed)
			{
				// Move is illegal and participant is notified about that.
				Header h(Communication::msg_header_t::SERVER_ERROR, owner_id, game_id);
				Message msg(h);
				_active_rooms[game_id]->deliver(msg, DeliverType::SAME);
			}
		}
		else if (msg_id == Communication::msg_header_t::CLIENT_SURRENDER)
		{
			// Other participant is notified that they won.
			Header h(Communication::msg_header_t::SERVER_END_GAME, owner_id, game_id);
			Message msg(h);
			// Sending SERVER_ID as winner means that game is surrendered.
			msg << SERVER_ID;
			_active_rooms[game_id]->deliver(msg, DeliverType::OPPOSITE);
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