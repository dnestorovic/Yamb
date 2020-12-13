#include "ClientConnection.h"

int main()
{
	const std::string host = "127.0.0.1";
	const std::string port = "5000";
	ConnectionClient client(host, port, [](Message& msg) { std::cout << msg << std::endl; });

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

	return 0;
}