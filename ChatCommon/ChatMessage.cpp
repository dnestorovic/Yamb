#include "ChatMessage.hpp"

template <typename T>
Chat::MessageHeader<T>::MessageHeader(T id)
{
	MessageHeader<T>(id, 0);
}

template <typename T>
Chat::MessageHeader<T>::MessageHeader(T id, uint32_t size)
	: id(id), size(size)
{}

template <typename T>
Chat::MessageHeader<T>::MessageHeader(const std::vector<uint8_t>& series)
{
	std::memcpy(&id, series.data(), sizeof(id));
	std::memcpy(&size, series.data() + sizeof(id), sizeof(size));
}

template <typename T>
T Chat::MessageHeader<T>::get_id() const
{
	return id;
}

template <typename T>
uint32_t Chat::MessageHeader<T>::get_size() const
{
	return size;
}

template <typename T>
void Chat::MessageHeader<T>::set_size(uint32_t new_size)
{
	size = new_size;
}

template <typename T>
const std::vector<uint8_t> Chat::MessageHeader<T>::serialize() const
{
	std::vector<uint8_t> store(sizeof(id) + sizeof(size));
	std::memcpy(store.data(), &id, sizeof(id));
	std::memcpy(store.data() + sizeof(id), &size, sizeof(size));

	return store;
}

template <typename T>
Chat::Message<T>::Message(Chat::MessageHeader<T> header)
	: header(header), body()
{}

template <typename T>
Chat::Message<T>::Message(MessageHeader<T> header, std::vector<uint8_t> body)
	: header(header), body(body)
{}

template <typename T>
size_t Chat::Message<T>::size() const
{
	return body.size();
}

template <typename T>
Chat::MessageHeader<T>& Chat::Message<T>::get_header()
{
	return header;
}

template <typename T>
std::vector<uint8_t>& Chat::Message<T>::get_body()
{
	return body;
}

template <typename T>
const std::vector<uint8_t> Chat::Message<T>::serialize() const
{
	std::vector<uint8_t> header_series = header.serialize();
	std::vector<uint8_t> body_series(body);
	header_series.insert(
		header_series.end(),
		std::make_move_iterator(body_series.begin()),
		std::make_move_iterator(body_series.end())
	);

	return header_series;
}

int main()
{

	return 0;
}