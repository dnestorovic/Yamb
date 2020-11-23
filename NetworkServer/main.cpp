#include <set>

#include "..\NetworkCommon\common.hpp"
#include "..\NetworkCommon\Message.hpp"
#include "..\NetworkCommon\ThreadSafeQueue.hpp"

using asio::ip::tcp;

typedef Communication::Message<Communication::MessageID> Message;
typedef Communication::MessageHeader<Communication::MessageID> Header;

class ChatParticipant
{
public:
	virtual ~ChatParticipant() = default;

	virtual void deliver(const Message& msg) = 0;
};

typedef std::shared_ptr<ChatParticipant> participant_ptr;

class ChatRoom
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

class ChatSession
	: public ChatParticipant,
	public std::enable_shared_from_this<ChatSession>
{
public:
	ChatSession(tcp::socket socket, ChatRoom& room)
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
	void read_header()
	{
		series_ptr_read.reset(new std::vector<uint8_t>(sizeof(Header)));

		asio::async_read(socket,
			asio::buffer(series_ptr_read->data(), sizeof(Header)),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					store_header = Header(*series_ptr_read);
					std::cout << store_header << std::endl;

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
	void parse_header();

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

					read_header();
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	void write_header()
	{
		std::vector<uint8_t> header_series = write_msgs.front().get_header().serialize();
		series_ptr_write.reset(new std::vector<uint8_t>(std::move(header_series)));

		asio::async_write(socket, asio::buffer(series_ptr_write->data(), series_ptr_write->size()),
			[this](const asio::error_code& ec, size_t)
			{
				if (!ec)
				{
					write_body();
				}
				else
				{
					room.leave(shared_from_this());
				}
			}
		);
	}

	void write_body()
	{
		std::vector<uint8_t> body_series = write_msgs.front().serialize();
		series_ptr_write.reset(new std::vector<uint8_t>(std::move(body_series)));

		asio::async_write(socket, asio::buffer(series_ptr_write->data(), series_ptr_write->size()),
			[this](const asio::error_code& ec, size_t)
			{
				if (!ec)
				{
					write_msgs.pop_front();

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

	std::unique_ptr<std::vector<uint8_t>> series_ptr_write;
	std::unique_ptr<std::vector<uint8_t>> series_ptr_read;
	tcp::socket socket;
	ChatRoom& room;
	Header store_header;
	Message store_message;
	ThreadSafeQueue<Message> write_msgs;
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

	// assinging idle work
	asio::io_context::work idle_work(context);

	context.run();

	/*std::thread thr_context([&context]() {context.run(); });
	thr_context.join();*/

	return 0;
}