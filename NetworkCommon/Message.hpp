#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "common.hpp"

typedef uint64_t owner_t;

namespace Communication
{
	enum class msg_header_t
	{
		MSG_FST, MSG_SND
	};

	template <typename T>
	class MessageHeader
	{
	private:
		T msg_id; // determines type of message
		owner_t owner_id; // determines who is the owner of message
		uint32_t size; // determines the size of message's body

	public:
		MessageHeader() = default;

		MessageHeader(T msg_id, owner_t owner_id)
			: msg_id(msg_id), owner_id(owner_id), size(0)
		{}

		MessageHeader(T msg_id, owner_t owner_id, uint32_t size)
			: msg_id(msg_id), owner_id(owner_id), size(size)
		{}

		// deserialization
		MessageHeader(const std::vector<uint8_t>& series)
		{
			std::memcpy(&msg_id, series.data(), sizeof(msg_id));
			std::memcpy(&owner_id, series.data() + sizeof(msg_id), sizeof(owner_id));
			std::memcpy(&size, series.data() + sizeof(msg_id) + sizeof(owner_id), sizeof(size));
		}

		T get_msg_id() const
		{
			return msg_id;
		}

		owner_t get_owner_id() const
		{
			return owner_id;
		}

		uint32_t get_size() const
		{
			return size;
		}

		static size_t get_header_size()
		{
			return sizeof(msg_id) + sizeof(owner_id) + sizeof(size);
		}

		void set_size(uint32_t new_size)
		{
			size = new_size;
		}

		// serialization is const on purpose - it's easy to invalidate it
		const std::vector<uint8_t> serialize() const
		{
			std::vector<uint8_t> store(sizeof(msg_id) + sizeof(owner_id) + sizeof(size));
			std::memcpy(store.data(), &msg_id, sizeof(msg_id));
			std::memcpy(store.data() + sizeof(msg_id), &owner_id, sizeof(owner_id));
			std::memcpy(store.data() + sizeof(msg_id) + sizeof(owner_id), &size, sizeof(size));

			return store;
		}

		MessageHeader<T>& operator= (const MessageHeader<T>& other)
		{
			msg_id = other.get_msg_id();
			owner_id = other.get_owner_id();
			size = other.get_size();

			return *this;
		}

		friend std::ostream& operator<< (std::ostream& ostr, const MessageHeader<T>& h)
		{
			// TODO: calling int operator
			ostr << "id=" << int(h.msg_id) << " owner id=" << h.owner_id << " size=" << h.size;
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

		Message(MessageHeader<T> header, const std::vector<uint8_t>& body)
			: header(header), body(body)
		{}

		uint32_t size() const
		{
			return header.get_size();
		}

		void set_header(const MessageHeader<T>& new_header)
		{
			header = new_header;
			body.clear(); // body's content becomes invalid upon changing header explicitly
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

		friend std::ostream& operator<< (std::ostream& ostr, const Message<T>& msg)
		{
			ostr << msg.header;

			return ostr;
		}

		template <typename DataType>
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

		template <typename DataType>
		friend Message<T>& operator<< (Message<T>& msg, const std::vector<DataType>& data)
		{
			for (auto item : data)
				msg << item;

			return msg;
		}

		template <typename DataType>
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