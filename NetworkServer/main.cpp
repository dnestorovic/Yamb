#include <set>

#include "..\NetworkCommon\common.hpp"
#include "..\NetworkCommon\Message.hpp"
#include "..\NetworkCommon\ThreadSafeQueue.hpp"

using asio::ip::tcp;

typedef Communication::Message<int> Message;

class ChatParticipant
{
public:
	virtual ~ChatParticipant() {}
	virtual void deliver(const Message& msg) = 0;
};

typedef std::shared_ptr<ChatParticipant> participant_ptr;

class ChatRoom
{
public:
	void join(participant_ptr participant)
	{
		participants.insert(participant);
		/*for (auto msg : msg_queue)
			participant->deliver(msg);*/
	}

	void leave(participant_ptr participant)
	{
		participants.erase(participant);
	}

	void deliver(const Message& msg)
	{
		//msg_queue.push_back(msg);

		for (const participant_ptr& participant : participants)
			participant->deliver(msg);
	}

private:
	std::set<participant_ptr> participants;
	//ThreadSafeQueue<Message> msg_queue;
};

class ChatSession
	: public ChatParticipant,
	public std::enable_shared_from_this<ChatSession>
{
public:
	ChatSession(tcp::socket socket, ChatRoom& room)
		: socket(std::move(socket)), room(room), read_msg()
	{}

	void start()
	{
		room.join(shared_from_this());
		//read_header();
	}

	void deliver(const Message& msg)
	{
		// TODO
	}

private:
	void read_header()
	{
		asio::async_read(socket,
			asio::buffer(&read_msg.get_header(), sizeof(read_msg.get_header())),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					std::cout << int(read_msg.get_header().get_id()) << std::endl;
					std::cout << read_msg.get_header().get_size() << std::endl;
					/*parse_header();
					read_body();*/
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	void parse_header()
	{

	}

	void read_body()
	{

	}

	tcp::socket socket;
	ChatRoom& room;
	Message read_msg;
	//ThreadSafeQueue<Message> write_msgs;
};

class ChatServer
{
public:
	ChatServer(asio::io_context& context, const tcp::endpoint& endpoint)
		: acceptor(context, endpoint)
	{
		accept();
	}

private:
	void accept()
	{
		acceptor.async_accept(
			[this](const asio::error_code& ec, tcp::socket socket)
			{
				if (!ec)
				{
					std::make_shared<ChatSession>(std::move(socket), room)->start();
				}

				accept();
			}
		);
	}

	tcp::acceptor acceptor;
	ChatRoom room;
};

int main()
{
	// for testing purposes
	const int port = 5000;

	// context will be shared for all clients
	asio::io_context context;

	// such initialization is used for accepting new connections
	tcp::endpoint endpoint(tcp::v4(), port);

	ChatServer server(context, endpoint);

	context.run();

	return 0;
}