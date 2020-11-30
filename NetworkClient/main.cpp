#include "..\NetworkCommon\ThreadSafeQueue.hpp"
#include "..\NetworkCommon\Message.hpp"
#include "..\NetworkCommon\common.hpp"

using asio::ip::tcp;

// these typedefs SHOULD be used
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

class ConnectionClient
{
public:
	ConnectionClient(asio::io_context& context, const tcp::resolver::results_type& endpoints)
		: series_ptr_read(nullptr), series_ptr_write(nullptr), context(context), socket(context)
	{
		connect(endpoints);
	}

	/*
	Closing socket. Used in case exception happens or at the very end of application's life.
	*/
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

	/*
	Starting writing message to the socket.
	*/
	void write(const Message& msg)
	{
		asio::post(context,
			[this, msg]()
			{
				bool in_progress = !write_msgs.empty();
				write_msgs.push_back(msg);
				
				// doesn't start writing in case it's already started
				if (!in_progress)
				{
					write_header();
				}
			}
		);
	}

private:
	/*
	Establishing connection to endpoints. It's working asynchronously."
	*/
	void connect(const tcp::resolver::results_type& endpoints)
	{
		asio::async_connect(socket, endpoints,
			[this](const asio::error_code& ec, tcp::endpoint)
			{
				if (!ec)
				{
					// reading message involves reading header first
					read_header();
				}
			}
		);
	}

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
					store_header_read = Header(*series_ptr_read);

					// after successfuly read header body is next to be read
					read_body();
				}
				else
				{
					close("read_header");
				}
			}
		);
	}

	/*
	Reads message's body from the opened socket. It's working asynchronously.
	*/
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

					// message has been received; start reading a new one
					read_header();
				}
				else
				{
					close("read_body");
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
					std::cout << ec.message() << std::endl;
					close("write_header");
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
					close("write_body");
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

	asio::io_context& context;
	tcp::socket socket; // socket depend on given context

	/*
	Since reading and writing can happend simultaneously separate instances are used
	for both reading and writing.
	*/
	Header store_header_write, store_header_read;
	Message store_message_write, store_message_read;
	ThreadSafeQueue<Message> write_msgs, read_msgs;
};

int main()
{
	// localhost
	const std::string host = "127.0.0.1";
	const std::string port = "5000";

	asio::io_context context;

	/*
	Resolver gives definite IP adresses for the requested domain.
	It's possible to have multiple IP adreeses for the single web domain.
	*/
	tcp::resolver resolver(context);
	auto endpoints = resolver.resolve(host, port);
	ConnectionClient client(context, endpoints);

	/*
	Since everything happens asynchronously we need to asign idle work
	to prevent context from closing prior to first I/O operation.
	*/
	asio::io_context::work idle_work(context);

	// staring in separate thread so it doesn't block main thread
	std::thread thr_context(
		[&context]()
		{
			context.run();
		}
	);

	std::string line;
	while (std::getline(std::cin, line))
	{
		Header header(Communication::msg_header_t::CLIENT_CHAT, 1, 123);
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