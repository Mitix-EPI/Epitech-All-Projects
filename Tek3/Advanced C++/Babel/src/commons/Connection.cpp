/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Connection
*/

#include "commons/Connection.hpp"

Connection::Connection(owner parent, asio::io_context &asioContext, asio::ip::tcp::socket socket, TsQueue<ownedPackage> &qIn) : _ioContext(asioContext), _socket(std::move(socket)), _QMessagesIn(qIn)
{
    _OwnerType = parent;
}

Connection::~Connection()
{
}

void Connection::ConnectToClient(unsigned int uid)
{
    if (_OwnerType == owner::server)
    {
        if (_socket.is_open()) {
            id = uid;
            ReadHeader();
        }
    }
}

bool Connection::ConnectToServer(const asio::ip::tcp::resolver::results_type &endpoints)
{
    if (_OwnerType == owner::client) {
        asio::async_connect(_socket, endpoints, 
        [this](std::error_code ec, asio::ip::tcp::endpoint endpoint)
        {
            if (!ec) {
                ReadHeader();
            }
        });
    }
    return true;
}

bool Connection::Disconnect()
{
    if (IsConnected())
        asio::post(_ioContext, [this]() {_socket.close();});
    return true;
}
bool Connection::IsConnected() const
{
    return _socket.is_open();
}
bool Connection::Send(const package &msg)
{
    asio::post(_ioContext,
    [this, msg]()
    {
        bool IsWriting = !_QMessagesOut.empty();
        _QMessagesOut.push_back(msg);
        if (!IsWriting)
            WriteHeader();

    });
    return true;
}
unsigned int Connection::GetID() const
{
    return id;
}
void Connection::ReadHeader()
{
    asio::async_read(_socket, asio::buffer(&_msgTmpIn.header, sizeof(package_header)),
    [this](std::error_code ec, std::size_t length)
    {
        if (!ec) {
            if (_msgTmpIn.header.size > 0) {
                _msgTmpIn.body.resize(_msgTmpIn.header.size);
                ReadBody();
            } else {
                AddToIncomingMessageQueue();
            }
        } else {
            std::cerr << "[" << id << "] Read Header Fail." << std::endl;
            _socket.close();
        }
    });
}
void Connection::ReadBody()
{
    asio::async_read(_socket, asio::buffer(_msgTmpIn.body.data(), _msgTmpIn.body.size()),
    [this](std::error_code ec, std::size_t length)
    {
        std::cout << "Read Body " << _msgTmpIn.header.size << std::endl;
        if (!ec) {
            AddToIncomingMessageQueue();
        } else {
            std::cout << "[" << id << "] Read Body Fail." << std::endl;
            _socket.close();
        }
    });
}
void Connection::WriteHeader()
{
    asio::async_write(_socket, asio::buffer(&_QMessagesOut.front().header, sizeof(package_header)),
    [this](std::error_code ec, std::size_t length)
    {
        if (!ec) {
            std::cout << "Read Body " << _QMessagesOut.front().header.size << std::endl;
            if (_QMessagesOut.front().body.size() > 0) {
                WriteBody();
            } else {
                _QMessagesOut.pop_front();
                if (!_QMessagesOut.empty())
                    WriteHeader();
            }
        } else {
            std::cout << "[" << id << "] Write Header Fail." << ec.message() << std::endl;
            _socket.close();
        }
    });
}
void Connection::WriteBody()
{
    asio::async_write(_socket, asio::buffer(_QMessagesOut.front().body.data(), _QMessagesOut.front().body.size()),
    [this](std::error_code ec, std::size_t length)
    {
        if (!ec) {
            _QMessagesOut.pop_front();
            if (!_QMessagesOut.empty())
                WriteHeader();
        } else {
            std::cout << "[" << id << "] Write Body Fail." << std::endl;
            _socket.close();
        }
    });
}
void Connection::AddToIncomingMessageQueue()
{
    if (_OwnerType == owner::server)
        _QMessagesIn.push_back({this->shared_from_this(), _msgTmpIn});
    else
        _QMessagesIn.push_back({nullptr,  _msgTmpIn});
    ReadHeader();
}