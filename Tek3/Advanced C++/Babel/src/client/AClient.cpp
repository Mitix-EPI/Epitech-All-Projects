/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** AClient
*/

#include "client/AClient.hpp"

AClient::AClient(): _socket(_context)
{
}

AClient::~AClient()
{
    Disconnect();
}

bool AClient::Connect(const std::string &host, const int port)
{
    try
    {

        asio::ip::tcp::resolver resolver(_context);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));
        _connection = std::make_unique<Connection>(Connection::owner::client, _context, asio::ip::tcp::socket(_context), _QMessagesIn);
        _connection->ConnectToServer(endpoints);
        thrContext = std::thread([this]() {_context.run();});

    }
    catch(const std::exception& e)
    {
        std::cerr << "Client Exeption: " << e.what() << std::endl;
    }
    
    return false;
}

void AClient::Disconnect(void)
{
    if (IsConnected())
        _connection->Disconnect();
    _context.stop();
    if (thrContext.joinable())
        thrContext.join();
    _connection.release();
}

bool AClient::IsConnected(void)
{
    if (_connection)
        return _connection->IsConnected();
    return false;
}

void AClient::Send(const package &msg)
{
    if (IsConnected())
        _connection->Send(msg);
}

TsQueue<ownedPackage> &AClient::getQMessages(void)
{
    return _QMessagesIn;
}