#include <set>

#include "../NetworkCommon/ThreadSafeQueue.hpp"
#include "../NetworkCommon/Message.hpp"
#include "../NetworkCommon/common.hpp"
#include "../NetworkCommon/RandomGenerator.hpp"

using asio::ip::tcp;

// these typedefs SHOULD be used
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

/*
Abstract class that represents participant in the chat.
*/
class ConnectionParticipant
{
public:
	virtual ~ConnectionParticipant() = default;

	// delivering given message to the participant
	virtual void deliver(const Message& msg) = 0;
};

typedef std::shared_ptr<ConnectionParticipant> participant_ptr;

/*
Rensposible for participant manipulation and message delivery.
*/
class ConnectionRoom
{
public:
	void join(participant_ptr participant)
	{
		participants.insert(participant);
	}

	void leave(participant_ptr participant)
	{
		participants.erase(participant);
	}

	void deliver(const Message& msg)
	{
		recent_msgs.push_back(msg);

		for (const participant_ptr& participant : participants)
			participant->deliver(msg);
	}

private:
	std::set<participant_ptr> participants;
	ThreadSafeQueue<Message> recent_msgs;
};

/*
Responsible for passing requests to the ChatRoom that are received from
participants via network.
*/
class ConnectionSession
	: public ConnectionParticipant,
	public std::enable_shared_from_this<ConnectionSession>
{
public:
	ConnectionSession(tcp::socket socket, ConnectionRoom& room)
		: socket(std::move(socket)), room(room), store_header(),
		store_message(), series_ptr_read(nullptr), series_ptr_write(nullptr)
	{}

	void start()
	{
		room.join(shared_from_this());
		read_header();
	}

	void deliver(const Message& msg)
	{
		bool in_progress = !write_msgs.empty();
		write_msgs.push_back(msg);

		if (!in_progress)
		{
			write_header();
		}
	}

private:
	/*
	Reads message's header from the opened socket. It's working asynchronously.
	*/
	void read_header()
	{
		series_ptr_read.reset(new std::vector<uint8_t>(Header::get_header_size()));

		asio::async_read(socket,
			asio::buffer(series_ptr_read->data(), Header::get_header_size()),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					store_header = Header(*series_ptr_read);
					std::cout << store_header << std::endl;

					// reading message involves reading header first
					read_body();
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	// TODO
	void parse_message()
	{
		Communication::msg_header_t msg_id = store_message.get_header().get_msg_id();					

		if(msg_id == Communication::msg_header_t::CLIENT_CREATE_GAME)
		{
			game_t new_game_id = store_message.get_header().get_game_id();

			// TODO
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_JOIN_GAME)
		{
			// TODO : Check max number of players
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_QUIT_GAME)
		{
			// TODO	
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_ROLL_DICE)
		{
			bool first_roll = false;

			//Indexes of selected dice
			std::vector<uint8_t> unselected;
			std::vector<uint8_t> new_rolling(NUM_OF_DICE);
		
			std::vector<std::pair<uint8_t,bool>> dice(NUM_OF_DICE);
			
			for(int i = 0; i < NUM_OF_DICE ; i++)
			{
				store_message >> dice[i].first;

				if(dice[0].first == 0)
				{
					first_roll = true;
					break;
				}

				if(dice[i].first > 0)
				{
					dice[i].second = true;
					new_rolling[i] = dice[i].first;	// Selected value still the same	
				}
				else
				{
					dice[i].second = false;
					unselected.push_back(i);
				}
			}	

			if(first_roll)
			{
				new_rolling = roll_the_dice(first_roll, NUM_OF_DICE);
			}
			else
			{
				uint8_t num_of_unselected = unselected.size();
				std::vector<uint8_t> new_unselected_rolling(num_of_unselected);
				new_unselected_rolling = roll_the_dice(first_roll, num_of_unselected);

				for(int i = 0; i < num_of_unselected; i++)
				{
					new_rolling[unselected[i]] = new_unselected_rolling[i];
				}
			}

			Communication::msg_header_t msg_id = Communication::msg_header_t::SERVER_ROLL_DICE;
			owner_t owner_id = store_message.get_header().get_owner_id();
			game_t game_id = store_message.get_header().get_game_id();
			uint32_t size = store_message.get_header().get_header_size();
			
			Header header(msg_id, owner_id, game_id);
			Message message(header);	

			for(auto x : new_rolling)
			{
				message << x;
			}

			// TODO: Send message to both clients
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_CHAT)
		{
			uint32_t len = store_message.get_header().get_size();
			std::vector<uint8_t> msg(len);
			for(int i = 0; i < len ; i++)
			{
				store_message >> msg[i];
			}
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_RETRIEVE_TICKET)
		{
			std::vector<uint8_t> info(2);
			for(int i = 0; i < 2 ; i++)
			{
				store_message >> info[i];
			}

			uint8_t row = info[0];
			uint8_t column = info[1]; 

			// TODO: uint8_t value = getFieldValue(row, column);  
			
		}
		else if(msg_id == Communication::msg_header_t::CLIENT_UPDATE_TICKET)
		{
			std::vector<uint8_t> info(3);
			for(int i = 0; i < 3 ; i++)
			{
				store_message>> info[i];
			}

			uint8_t row = info[1];
			uint8_t column = info[2]; 
			uint8_t new_value = info[3]; 

			// TODO: .updateField(row, column, new_value)
			
		}



	}

	/*
	Reads message's body from the opened socket. It's working asynchronously.
	*/
	void read_body()
	{
		std::vector<uint8_t> body_series(store_header.get_size());
		series_ptr_read.reset(new std::vector<uint8_t>(std::move(body_series)));

		asio::async_read(socket,
			asio::buffer(series_ptr_read->data(), series_ptr_read->size()),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					store_message.set_header(store_header);
					store_message << *series_ptr_read;
					room.deliver(store_message);

					parse_message();

					// message has been received; start reading a new one
					read_header();
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	/*
	Writes message's header to the opened socket. It's working asynchronously.
	*/
	void write_header()
	{
		std::vector<uint8_t> header_series = write_msgs.front().get_header().serialize();
		series_ptr_write.reset(new std::vector<uint8_t>(std::move(header_series)));

		asio::async_write(socket, asio::buffer(series_ptr_write->data(), series_ptr_write->size()),
			[this](const asio::error_code& ec, size_t)
			{
				if (!ec)
				{
					// writing message involes writing header first
					write_body();
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	/*
	Writes message's body to the opened socket. It's working asynchronously.
	*/
	void write_body()
	{
		std::vector<uint8_t> body_series = write_msgs.front().serialize();
		series_ptr_write.reset(new std::vector<uint8_t>(std::move(body_series)));

		asio::async_write(socket, asio::buffer(series_ptr_write->data(), series_ptr_write->size()),
			[this](const asio::error_code& ec, size_t)
			{
				if (!ec)
				{
					// pop written message from not-written queue
					write_msgs.pop_front();

					// if there are more messages to be written, start writing a new one
					if (!write_msgs.empty())
						write_header();
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	/*
	ASIO buffers point to data which don't have local scope. For that purpose smart pointers
	are used for easier manipulation with data on heap. These poiners serve purpose of placeholders.
	*/
	std::unique_ptr<std::vector<uint8_t>> series_ptr_write;
	std::unique_ptr<std::vector<uint8_t>> series_ptr_read;

	tcp::socket socket;
	ConnectionRoom& room;

	Header store_header;
	Message store_message;
	ThreadSafeQueue<Message> write_msgs;
};

class ConnectionServer
{
public:
	ConnectionServer(asio::io_context& context, const tcp::endpoint& endpoint)
		: acceptor(context, endpoint)
	{
		accept();
	}

private:
	/*
	Accepting new participant. Current implementation allows unlimited number of participants.

	TODO: accept only two participants for a single game.
	*/
	void accept()
	{
		acceptor.async_accept(
			[this](const asio::error_code& ec, tcp::socket socket)
			{
				if (!ec)
				{
					std::make_shared<ConnectionSession>(std::move(socket), room)->start();
				}

				accept();
			}
		);
	}

	tcp::acceptor acceptor;
	ConnectionRoom room;
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