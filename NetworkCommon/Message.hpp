#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "common.hpp"

namespace Communication
{
	enum class MessageID
	{
		MSG_FST, MSG_SND
	};

	template <typename T>
	class MessageHeader
	{
	private:
		T id;
		uint32_t size;

	public:
		MessageHeader() = default;

		MessageHeader(T id)
			: id(id), size(0)
		{}

		MessageHeader(T id, uint32_t size)
			: id(id), size(size)
		{}

		// deserialization
		MessageHeader(const std::vector<uint8_t>& series)
		{
			std::memcpy(&id, series.data(), sizeof(id));
			std::memcpy(&size, series.data() + sizeof(id), sizeof(size));
		}

		T get_id() const
		{
			return id;
		}

		uint32_t get_size() const
		{
			return size;
		}

		uint32_t get_header_size() const
		{
			return sizeof(T) + sizeof(size);
		}

		void set_size(uint32_t new_size)
		{
			size = new_size;
		}

		// serialization is const on purpose - it's easy to invalidate it
		const std::vector<uint8_t> serialize() const
		{
			std::vector<uint8_t> store(sizeof(id) + sizeof(size));
			std::memcpy(store.data(), &id, sizeof(id));
			std::memcpy(store.data() + sizeof(id), &size, sizeof(size));

			return store;
		}

		MessageHeader<T>& operator= (const MessageHeader<T>& other)
		{
			id = other.get_id();
			size = other.get_size();

			return *this;
		}

		template <typename T>
		friend std::ostream& operator<< (std::ostream& ostr, const MessageHeader<T>& h)
		{
			// TODO: calling int operator
			ostr << "id=" << int(h.id) << " " << "size=" << h.size;
			return ostr;
		}
	};

	template <typename T>
	class Message
	{
	public:
		Message() = default;

		Message(MessageHeader<T> header)
			: header(header), body()
		{}

		Message(MessageHeader<T> header, std::vector<uint8_t> body)
			: header(header), body(body)
		{}

		uint32_t size() const
		{
			return header.get_size();
		}

		void set_header(const MessageHeader<T>& new_header)
		{
			header = new_header;
			body.clear();
		}

		MessageHeader<T>& get_header()
		{
			return header;
		}

		// returned as reference because of potential large vector
		std::vector<uint8_t>& get_body()
		{
			return body;
		}

		void set_body(const std::vector<uint8_t>& new_body) {
			new_body.resize(new_body.size());
			std::copy(new_body.begin(), new_body.end(), body.begin());
			header.set_size(body.size());
		}

		// serialization is const on purpose - it's easy to invalidate it
		const std::vector<uint8_t> serialize() const
		{
			return body;
		}

		template <typename T>
		friend std::ostream& operator<< (std::ostream& ostr, const Message<T>& msg)
		{
			ostr << msg.header;

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
			msg.header.set_size(msg.body.size());

			return msg;
		}

		template <typename T, typename DataType>
		friend Message<T>& operator<< (Message<T>& msg, const std::vector<DataType>& data)
		{
			for (auto item : data)
				msg << item;

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

#endif