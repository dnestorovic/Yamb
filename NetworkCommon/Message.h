#ifndef MESSAGE_H
#define MESSAGE_H

#include "common.h"

namespace Communication {
enum class msg_header_t {
  CLIENT_CREATE_GAME,  // server should initialize a new game [body: empty]
  CLIENT_JOIN_GAME,    // server should accept new participant in the existing
                       // game [body: empty]
  CLIENT_CHAT,         // participant sent a chat message [body: n x (char)]
  CLIENT_INTERMEDIATE_MOVE,  // participant sent dice values [body: 6 x
                             // (uint8_t)]
  CLIENT_FINISH_MOVE,   // participant sent dice values and ticket field [body:
                        // row(uint8_t), col(uint8_t), 6 x (uint8_t)]
  CLIENT_SURRENDER,     // participant surrendered the game [body: empty]
  CLIENT_ANNOUNCEMENT,  // participant wants to play announcement move
                        // [body: row(uint8_t)]
  SERVER_END_GAME,      // server notified participants who has won in the game
                        // [body: (uint16_t)]
  SERVER_INTERMEDIATE_MOVE,  // server notified participants for the new roll
                             // [body: 6 x (int8_t)]
  SERVER_FINISH_MOVE,  // server notified participant that someone has ended a
                       // move [body: row(uint8_t), col(uint8_t),
                       // value(uint8_t)]
  SERVER_PLAY_MOVE,  // server requested from participant to play a move [body:
                     // empty]
  SERVER_CHAT,  // participant got a new message from server [body: n x (char)]
  SERVER_OK,  // server sent notification to the participant that last operation
              // is OK [body: empty]
  SERVER_ERROR  // server sent notification to the participant that last
                // operation is ERROR [body: empty]
};

template <typename T>
class MessageHeader {
 private:
  T _msg_id;          // determines type of message
  owner_t _owner_id;  // determines who is the owner of message
  game_t _game_id;    // determines id of the game
  uint32_t _size;     // determines the size of message's body

 public:
  // Basically sizeof operator.
  static size_t get_header_size() {
    return sizeof(_msg_id) + sizeof(_owner_id) + sizeof(_game_id) + sizeof(_size);
  }

  // Applying rule of five.
  MessageHeader() = default;
  ~MessageHeader() = default;
  MessageHeader(const MessageHeader<T>&) = default;
  MessageHeader(MessageHeader<T>&&) = default;
  MessageHeader<T>& operator=(const MessageHeader<T>&) = default;
  MessageHeader<T>& operator=(MessageHeader<T>&&) = default;

  MessageHeader(T msg_id, owner_t owner_id, game_t game_id, uint32_t size)
      : _msg_id(msg_id), _owner_id(owner_id), _game_id(game_id), _size(size) {}

  MessageHeader(T msg_id, owner_t owner_id, game_t game_id)
      : MessageHeader(msg_id, owner_id, game_id, 0) {}

  // Deserialization.
  MessageHeader(const std::vector<uint8_t>& series) {
    std::memcpy(&_msg_id, series.data(), sizeof(_msg_id));
    std::memcpy(&_owner_id, series.data() + sizeof(_msg_id), sizeof(_owner_id));
    std::memcpy(&_game_id, series.data() + sizeof(_msg_id) + sizeof(_owner_id),
                sizeof(_game_id));
    std::memcpy(
        &_size,
        series.data() + sizeof(_msg_id) + sizeof(_owner_id) + sizeof(_game_id),
        sizeof(_size));
  }

  // Getters for all data members.
  T get_msg_id() const { return _msg_id; }
  owner_t get_owner_id() const { return _owner_id; }
  game_t get_game_id() const { return _game_id; }
  uint32_t get_size() const { return _size; }

  // Setters for msg_id and size.
  void set_msg_id(T new_msg_id) { _msg_id = new_msg_id; }
  void set_size(uint32_t new_size) { _size = new_size; }

  // Serialization is const on purpose - it's easy to invalidate it
  const std::vector<uint8_t> serialize() const {
    std::vector<uint8_t> store(MessageHeader::get_header_size());
    std::memcpy(store.data(), &_msg_id, sizeof(_msg_id));
    std::memcpy(store.data() + sizeof(_msg_id), &_owner_id, sizeof(_owner_id));
    std::memcpy(store.data() + sizeof(_msg_id) + sizeof(_owner_id), &_game_id,
                sizeof(_game_id));
    std::memcpy(
        store.data() + sizeof(_msg_id) + sizeof(_owner_id) + sizeof(_game_id),
        &_size, sizeof(_size));

    return store;
  }

  friend std::ostream& operator<<(std::ostream& ostr,
                                  const MessageHeader<T>& h) {
    ostr << "msg_id=" << int(h._msg_id) << " owner_id=" << h._owner_id
         << " game_id=" << h._game_id << " size=" << h._size;
    return ostr;
  }
};

template <typename T>
class Message {
 public:
  Message() = default;

  Message(MessageHeader<T> header)
      : Message(header, std::vector<uint8_t>()) {}

  Message(MessageHeader<T> header, const std::vector<uint8_t>& body)
      : header(header), body(body) {}

  uint32_t size() const { return header.get_size(); }

  void set_header(const MessageHeader<T>& new_header) {
    header = new_header;
    // Body's content becomes invalid upon changing header explicitly.
    body.clear();
  }

  // Getters for all data members.
  MessageHeader<T>& get_header() { return header; }
  // Returned as reference because of potential large vector.
  std::vector<uint8_t>& get_body() { return body; }

  // Serialization is const on purpose - it's easy to invalidate it.
  const std::vector<uint8_t> serialize() const { return body; }

  friend std::ostream& operator<<(std::ostream& ostr, const Message<T>& msg) {
    ostr << msg.header;

    return ostr;
  }

  template <typename DataType>
  friend Message<T>& operator<<(Message<T>& msg, const DataType& data) {
    static_assert(std::is_standard_layout<DataType>::value,
                  "Data cannot be serialized");

    // Size prior to body's expansion.
    size_t prev_size = msg.body.size();

    // Body's expansion.
    msg.body.resize(msg.body.size() + sizeof(DataType));

    // Appending new element to the end.
    std::memcpy(msg.body.data() + prev_size, &data, sizeof(DataType));

    // Recalculating size.
    msg.header.set_size(msg.body.size());

    return msg;
  }

  template <typename DataType>
  friend Message<T>& operator<<(Message<T>& msg,
                                const std::vector<DataType>& data) {
    for (auto item : data) msg << item;

    return msg;
  }

  template <typename DataType>
  friend Message<T>& operator>>(Message<T>& msg, DataType& data) {
    static_assert(std::is_standard_layout<DataType>::value,
                  "Data cannot be serialized");

    // Size after body's shrinkage.
    size_t next_size = msg.body.size() - sizeof(DataType);

    // Coppying last element to data.
    std::memcpy(&data, msg.body.data() + next_size, sizeof(DataType));

    // Shrinking body.
    msg.body.resize(next_size);

    // Recalculating size.
    msg.header.set_size(msg.size());

    return msg;
  }

 private:
  MessageHeader<T> header;
  std::vector<uint8_t> body;
};
}  // namespace Communication

// Use these typedefs.
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

#endif  // MESSAGE_H
