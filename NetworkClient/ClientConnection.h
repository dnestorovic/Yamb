#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include "../NetworkCommon/ThreadSafeQueue.h"
#include "../NetworkCommon/Message.h"
#include "../NetworkCommon/common.h"
#include "../NetworkCommon/RandomGenerator.h"

using asio::ip::tcp;

// these typedefs SHOULD be used
typedef Communication::Message<Communication::msg_header_t> Message;
typedef Communication::MessageHeader<Communication::msg_header_t> Header;

class ConnectionClient
{
public:
    ConnectionClient(const std::string host, const std::string port, std::function<void(Message&)> callback)
        : series_ptr_write(nullptr)
        , series_ptr_read(nullptr)
        , context(new asio::io_context())
        , socket(*context)
        , read_callback(callback)
        , game_id(generate_id<game_t>())
        , owner_id(generate_id<owner_t>())
    {
        tcp::resolver resolver(*context);
        auto endpoints = resolver.resolve(host, port);
        connect(endpoints);

        asio::io_context::work idle_work(*context);

        std::thread *thr_context = new std::thread(
            [this]()
            {
                context->run();
            }
        );
        thr_context->detach();

        // init message is responsible for getting placed in the correct game
        // player who has created the game has id = 1
        // TODO: consider replacing ID with user_name
        Header initHeader(Communication::msg_header_t::CLIENT_CREATE_GAME, owner_id, game_id);
        Message initMessage(initHeader);
        write(initMessage);
    }

    ConnectionClient(const std::string host, const std::string port, std::function<void(Message&)> callback, game_t game_id)
        : series_ptr_write(nullptr)
        , series_ptr_read(nullptr)
        , context(new asio::io_context())
        , socket(*context)
        , read_callback(callback)
        , game_id(game_id)
        , owner_id(generate_id<owner_t>())
    {
        tcp::resolver resolver(*context);
        auto endpoints = resolver.resolve(host, port);
        connect(endpoints);

        asio::io_context::work idle_work(*context);

        std::thread *thr_context = new std::thread(
            [this]()
            {
                context->run();
            }
        );
        thr_context->detach();

        // init message is responsible for getting placed in the correct game
        // player who has created the game has id = 1
        // TODO: consider replacing ID with user_name
        Header initHeader(Communication::msg_header_t::CLIENT_JOIN_GAME, owner_id, game_id);
        Message initMessage(initHeader);
        write(initMessage);
    }

    /*
    Closing socket. Used in case exception happens or at the very end of application's life.
    */
    void close(const std::string& log)
    {
        std::cerr << "[close]: " << log << std::endl;

        asio::post(*context,
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
        asio::post(*context,
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

    owner_t get_owner_id() const
    {
        return owner_id;
    }

    game_t get_game_id() const
    {
        return game_id;
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

                    Communication::msg_header_t msg_id = store_message_read.get_header().get_msg_id();

                    if(msg_id == Communication::msg_header_t::SERVER_PLAY_MOVE)
                    {
                        // .playMove()
                    }
                    else if(msg_id == Communication::msg_header_t::SERVER_END_GAME)
                    {
                        uint8_t winner;
                        store_message_read >> winner;

                        // TODO : Winner check and gui messages
                        close("End of the game!");
                    }
                    else if(msg_id == Communication::msg_header_t::SERVER_ROLL_DICE)
                    {
                        //First element in pair is dice value and second is selection indicator
                        std::vector<std::pair<uint8_t,bool>> dice(NUM_OF_DICE);
                        for(int i = 0; i < NUM_OF_DICE ; i++)
                        {
                            store_message_read >> dice[i].first;
                            if(dice[i].first > 0)
                                dice[i].second = true;
                            else
                                dice[i].second = false;
                        }
                    }
                    else if(msg_id == Communication::msg_header_t::SERVER_CHAT)
                    {
                        read_callback(store_message_read);
                    }
                    else if(msg_id == Communication::msg_header_t::SERVER_RETRIEVE_TICKET)
                    {
                        std::vector<uint8_t> info(4);
                        for(int i = 0; i < 4 ; i++)
                        {
                            store_message_read >> info[i];
                        }

                        uint8_t player_id = info[0];
                        uint8_t row = info[1];
                        uint8_t column = info[2];
                        uint8_t value = info[3];

                        if(row == -1 && column == -1)
                        {
                            // TODO: Call function that returns total value
                        }
                        else
                        {
                            // TODO: Call function to update ticket with id = player_id
                        }
                    }
                    else if(msg_id == Communication::msg_header_t::SERVER_OK)
                    {
                        read_callback(store_message_read);
                    }
                    else if(msg_id == Communication::msg_header_t::SERVER_ERROR)
                    {
                        // TODO
                    }

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

    asio::io_context *context;
    tcp::socket socket; // socket depend on given context

    /*
    Since reading and writing can happend simultaneously separate instances are used
    for both reading and writing.
    */
    Header store_header_write, store_header_read;
    Message store_message_write, store_message_read;
    ThreadSafeQueue<Message> write_msgs, read_msgs;

    // function to be called after message is received
    std::function<void(Message&)> read_callback;

    game_t game_id;
    owner_t owner_id;
};

#endif // CLIENTCONNECTION_H
