#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include "../NetworkCommon/Message.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "../NetworkCommon/ThreadSafeQueue.h"
#include "../NetworkCommon/common.h"

using asio::ip::tcp;

// USE THESE TYPEDEFS
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

class ConnectionClient {
 public:
  ConnectionClient(const std::string host, const std::string port,
                   std::function<void(Message&)> callback, game_t game_id)
      : _series_ptr_write(nullptr),
        _series_ptr_read(nullptr),
        _context(new asio::io_context()),
        _socket(*_context),
        _read_callback(callback),
        _game_id(game_id),
        _owner_id(generate_id<owner_t>()) {
    tcp::resolver resolver(*_context);
    auto endpoints = resolver.resolve(host, port);
    connect(endpoints);

    asio::io_context::work idle_work(*_context);

    std::thread* thr_context = new std::thread([this]() { _context->run(); });
    thr_context->detach();

    // Init message is responsible for getting placed in the correct game.
    if (_game_id) {
      // Non-zero game_id means that such game should already exist.
      Header initHeader(Communication::msg_header_t::CLIENT_JOIN_GAME,
                        _owner_id, _game_id);
      Message initMessage(initHeader);
      write(initMessage);
    } else {
      // Zero game_id means that new game should be created.
      _game_id = generate_id<game_t>();
      Header initHeader(Communication::msg_header_t::CLIENT_CREATE_GAME,
                        _owner_id, _game_id);
      Message initMessage(initHeader);
      write(initMessage);
    }
  }

  void set_read_callback(std::function<void(Message&)> read_callback) {
    _read_callback = read_callback;
  }

  // Closing socket. Used in case exception happens or at the very end of
  // application's life.
  void close(const std::string& log) {
    std::cerr << "[close]: " << log << std::endl;

    asio::post(*_context, [this]() {
      try {
        _socket.shutdown(tcp::socket::shutdown_both);
      } catch (const boost::wrapexcept<std::system_error>) {
        // Will trigger if socket wasn't opened. Intended behavior.
      }
    });
  }

  // Starting writing message to the socket.
  void write(const Message& msg) {
    asio::post(*_context, [this, msg]() {
      bool in_progress = !_write_msgs.empty();
      _write_msgs.push_back(msg);

      // Doesn't start writing in case it's already started.
      if (!in_progress) {
        write_header();
      }
    });
  }

  owner_t get_owner_id() const { return _owner_id; }

  game_t get_game_id() const { return _game_id; }

 private:
  // Establishing connection to endpoints. It's working asynchronously.
  void connect(const tcp::resolver::results_type& endpoints) {
    asio::async_connect(_socket, endpoints,
                        [this](const asio::error_code& ec, tcp::endpoint) {
                          if (!ec) {
                            // Reading message involves reading header first.
                            read_header();
                          }
                        });
  }

  // Reads message's header from the opened socket. It's working asynchronously.
  void read_header() {
    _series_ptr_read.reset(new std::vector<uint8_t>(Header::get_header_size()));

    asio::async_read(
        _socket,
        asio::buffer(_series_ptr_read->data(), Header::get_header_size()),
        [this](const asio::error_code& ec, std::size_t) {
          if (!ec) {
            _store_header_read = Header(*_series_ptr_read);

            // After successfuly read header body is next to be read.
            read_body();
          } else {
            close("read_header");
          }
        });
  }

  // Reads message's body from the opened socket. It's working asynchronously.
  void read_body() {
    std::vector<uint8_t> body_series(_store_header_read.get_size());
    _series_ptr_read.reset(new std::vector<uint8_t>(std::move(body_series)));

    asio::async_read(
        _socket,
        asio::buffer(_series_ptr_read->data(), _series_ptr_read->size()),
        [this](const asio::error_code& ec, std::size_t) {
          if (!ec) {
            _store_message_read.set_header(_store_header_read);
            _store_message_read << *_series_ptr_read;
            // Calling proper callback for parsing received message.
            _read_callback(_store_message_read);

            // Message has been received. Start reading a new one.
            read_header();
          } else {
            close("read_body");
          }
        });
  }

  // Writes message's header to the opened socket. It's working asynchronously.
  void write_header() {
    std::vector<uint8_t> header_series =
        _write_msgs.front().get_header().serialize();
    _series_ptr_write.reset(new std::vector<uint8_t>(std::move(header_series)));

    asio::async_write(
        _socket,
        asio::buffer(_series_ptr_write->data(), _series_ptr_write->size()),
        [this](const asio::error_code& ec, size_t) {
          if (!ec) {
            // Writing message involes writing header first.
            write_body();
          } else {
            close("write_header");
          }
        });
  }

  // Writes message's body to the opened socket. It's working asynchronously.
  void write_body() {
    std::vector<uint8_t> body_series = _write_msgs.front().serialize();
    _series_ptr_write.reset(new std::vector<uint8_t>(std::move(body_series)));

    asio::async_write(
        _socket,
        asio::buffer(_series_ptr_write->data(), _series_ptr_write->size()),
        [this](const asio::error_code& ec, size_t) {
          if (!ec) {
            // Pop written message from not-written queue.
            _write_msgs.pop_front();

            // If there are more messages to be written, start writing a new
            // one.
            if (!_write_msgs.empty()) write_header();
          } else {
            close("write_body");
          }
        });
  }

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
  ThreadSafeQueue<Message> _write_msgs, read_msgs;

  // Function to be called after message is received.
  std::function<void(Message&)> _read_callback;

  game_t _game_id;
  owner_t _owner_id;
};

#endif  // CLIENTCONNECTION_H
