#ifndef CONNECTION_H
#define CONNECTION_H

#include "../NetworkCommon/Message.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "../NetworkCommon/ThreadSafeQueue.h"
#include "../NetworkCommon/common.h"

using asio::ip::tcp;

class Connection {
 public:
  Connection(const std::string host, const std::string port,
             std::function<void(Message &)> callback, game_t game_id);

  // Getter for is_my_turn.
  bool get_is_my_turn() const;

  // Setter for is_my_turn.
  void set_is_my_turn(bool is_my_turn);

  // Setter for read_callback.
  void set_read_callback(std::function<void(Message &)> read_callback);

  // Closing socket. Used in case exception happens or at the very end of
  // application's life.
  void close(const std::string &log);

  // Starting writing message to the socket.
  void write(const Message &msg);

  // Getter for owner_id.
  owner_t get_owner_id() const;

  // Getter for game_id.
  game_t get_game_id() const;

 private:
  // Establishing connection to endpoints. It's working asynchronously.
  void connect(const tcp::resolver::results_type &endpoints);

  // Reads message's header from the opened socket. It's working asynchronously.
  void read_header();

  // Reads message's body from the opened socket. It's working asynchronously.
  void read_body();

  // Writes message's header to the opened socket. It's working asynchronously.
  void write_header();

  // Writes message's body to the opened socket. It's working asynchronously.
  void write_body();

  // ASIO buffers point to data which don't have local scope. For that purpose
  // smart pointers are used for easier manipulation with data on heap. These
  // poiners serve purpose of placeholders.
  std::unique_ptr<std::vector<uint8_t>> _series_ptr_write;
  std::unique_ptr<std::vector<uint8_t>> _series_ptr_read;

  std::unique_ptr<asio::io_context> _context;
  // socket depend on given context
  tcp::socket _socket;

  // Since reading and writing can happend simultaneously separate instances are
  // used for both reading and writing.
  Header _store_header_write, _store_header_read;
  Message _store_message_write, _store_message_read;
  ThreadSafeQueue<Message> _write_msgs, _read_msgs;

  // Function to be called after message is received.
  std::function<void(Message &)> _read_callback;

  game_t _game_id;
  owner_t _owner_id;

  bool _is_my_turn;
};

#endif  // CONNECTION_H
