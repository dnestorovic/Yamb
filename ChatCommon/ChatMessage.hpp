#include "common.hpp"

namespace Chat
{
	template <typename T>
	class MessageHeader
	{
	private:
		T id;
		uint32_t size;

	public:
		MessageHeader(T id);

		MessageHeader(T id, uint32_t size);

		// deserialization
		MessageHeader(const std::vector<uint8_t>& series);

		T get_id() const;

		uint32_t get_size() const;

		void set_size(uint32_t new_size);

		// serialization is const on purpose - it's easy to invalidate it
		const std::vector<uint8_t> serialize() const;
	};

	template <typename T>
	class Message
	{
	public:
		Message(MessageHeader<T> header);

		Message(MessageHeader<T> header, std::vector<uint8_t> body);

		size_t size() const;

		MessageHeader<T>& get_header();

		// returned as reference because of potential large vector
		std::vector<uint8_t>& get_body();

		// serialization is const on purpose - it's easy to invalidate it
		const std::vector<uint8_t> serialize() const;

		template <typename T>
		friend std::ostream& operator<< (std::ostream& ostr, const Message<T>& msg)
		{
			ostr << "id=" << int(msg.header.get_id()) << " size=" << msg.header.get_size();

			return ostr;
		}

		template <typename T, typename DataType>
		friend Message<T>& operator<< (Message<T>& msg, const DataType& data)
		{
			static_assert(std::is_standard_layout<DataType>::value, "Data cannot be serialized");

			// size prior to body's expansion
			size_t prev_size = msg.body.size();

			// body's expansion
			msg.body.resize(msg.body.size() + sizeof(DataType));

			// appending new element to the end
			std::memcpy(msg.body.data() + prev_size, &data, sizeof(DataType));

			// recalculating size
			msg.header.set_size(msg.size());

			return msg;
		}

		template <typename T, typename DataType>
		friend Message<T>& operator>> (Message<T>& msg, DataType& data)
		{
			static_assert(std::is_standard_layout<DataType>::value, "Data cannot be serialized");

			// size after body's shrinkage
			size_t next_size = msg.body.size() - sizeof(DataType);

			// coppying last element to data
			std::memcpy(&data, msg.body.data() + next_size, sizeof(DataType));

			// shrinking body
			msg.body.resize(next_size);

			// recalculating size
			msg.header.set_size(msg.size());

			return msg;
		}

	private:
		MessageHeader<T> header;
		std::vector<uint8_t> body;
	};
}
