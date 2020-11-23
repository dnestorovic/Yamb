#include "..\NetworkCommon\ThreadSafeQueue.hpp"
#include "..\NetworkCommon\Message.hpp"
#include "..\NetworkCommon\common.hpp"

using asio::ip::tcp;

typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

class ChatClient
{
public:
	ChatClient(asio::io_context& context, const tcp::resolver::results_type& endpoints)
		: series_ptr_read(nullptr), series_ptr_write(nullptr), context(context), socket(context)
	{
		connect(endpoints);
	}

	void close(const std::string& log)
	{
		std::cerr << "[close]: " << log << std::endl;

		asio::post(context,
			[this]()
			{
				socket.close();
			}
		);
	}

	void write(const Message& msg)
	{
		asio::post(context,
			[this, msg]()
			{
				bool in_progress = !write_msgs.empty();
				write_msgs.push_back(msg);
				
				if (!in_progress)
				{
					write_header();
				}
			}
		);
	}

private:
	void connect(const tcp::resolver::results_type& endpoints)
	{
		asio::async_connect(socket, endpoints,
			[this](const asio::error_code& ec, tcp::endpoint)
			{
				if (!ec)
				{
					read_header();
				}
			}
		);
	}

	void read_header()
	{
		series_ptr_read.reset(new std::vector<uint8_t>(Header::get_header_size()));

		asio::async_read(socket,
			asio::buffer(series_ptr_read->data(), Header::get_header_size()),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					store_header_read = Header(*series_ptr_read);

					read_body();
				}
				else
				{
					close("read_header");
				}
			}
		);
	}

	void read_body()
	{
		std::vector<uint8_t> body_series(store_header_read.get_size());
		series_ptr_read.reset(new std::vector<uint8_t>(std::move(body_series)));

		asio::async_read(socket,
			asio::buffer(series_ptr_read->data(), series_ptr_read->size()),
			[this](const asio::error_code& ec, std::size_t)
			{
				if (!ec)
				{
					store_message_read.set_header(store_header_read);
					store_message_read << *series_ptr_read;
					std::cout << store_message_read << std::endl;

					read_header();
				}
				else
				{
					close("read_body");
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
					close("write_header");
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
					close("write_body");
				}
			}
		);
	}

	std::unique_ptr<std::vector<uint8_t>> series_ptr_write; // placeholder for serialized data
	std::unique_ptr<std::vector<uint8_t>> series_ptr_read; // placeholder for serialized data
	asio::io_context& context;
	tcp::socket socket;
	Header store_header_write, store_header_read;
	Message store_message_write, store_message_read;
	ThreadSafeQueue<Message> write_msgs, read_msgs;
};

int main()
{
	const std::string host = "127.0.0.1";
	const std::string port = "5000";

	asio::io_context context;

	tcp::resolver resolver(context);
	auto endpoints = resolver.resolve(host, port);
	ChatClient client(context, endpoints);

	asio::io_context::work idle_work(context);

	std::thread thr_context(
		[&context]()
		{
			context.run();
		}
	);

	std::string line;
	while (std::getline(std::cin, line))
	{
		Header header(Communication::msg_header_t::MSG_FST, 1);
		Message message(header);
		for (char c : line)
			message << c;
		std::cout << message << std::endl;
		client.write(message);
	}
	client.close("main");
	thr_context.join();

	return 0;
}