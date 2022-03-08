/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** AServer
*/

#include "server/AServer.hpp"

AServer::AServer(int port) : _asioAcceptor(_asioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
    
}
AServer::~AServer()
{
    Stop();
}
bool AServer::Start()
{
    try {
        WaitForClientConnection();
        _threadContext = std::thread([this]() {_asioContext.run();});
    } catch (std::exception &e) {
        std::cerr << "[SERVER] Exception: " << e.what() << std::endl;
        return false;
    }

    std::cout << "[SERVER] Started!" << std::endl;
    return true;
}
void AServer::Stop()
{
    _asioContext.stop();
    if (_threadContext.joinable())
        _threadContext.join();
}
void AServer::WaitForClientConnection()
{
    _asioAcceptor.async_accept(
        [this] (std::error_code ec, asio::ip::tcp::socket socket)
        {
            if (!ec) {
                std::cout << "[SERVER] New Connection: " << socket.remote_endpoint() << std::endl;
                std::shared_ptr<Connection> newconn = std::make_shared<Connection>(Connection::owner::server, _asioContext, std::move(socket), _QMessagesIn);
                if (OnClientConnect(newconn)) {
                    _deqConnections.push_back(std::move(newconn));
                    _deqConnections.back()->ConnectToClient(_IdCounter++);
                    std::cout << "[Client " << _deqConnections.back()->GetID() << "] Connected" << std::endl;
                } else {
                    std::cout << "[------] Connection Denied" << std::endl;
                }
            } else {
                std::cerr << "[SERVER] New Connection Error: " << ec.message() << std::endl;
            }
            WaitForClientConnection();
        }
    );
}
void AServer::SendToClient(std::shared_ptr<Connection> client, const package &msg)
{
    if (client && client->IsConnected()) {
        client->Send(msg);
    } else {
        // OnClientDisconnect(client);
        client.reset();
        _deqConnections.erase(std::remove(_deqConnections.begin(), _deqConnections.end(), client), _deqConnections.end());
    }
}
void AServer::SendToAllClient(const package &msg, std::shared_ptr<Connection> IgnoreClient)
{
    bool InvalidClientExists = false;

    for (auto &client : _deqConnections) {
        if (client && client->IsConnected()) {
            if (client != IgnoreClient)
                client->Send(msg);
        } else {
            std::cout << "C'est par la que je passe" << std::endl;
            // OnClientDisconnect(client);
            client.reset();
            InvalidClientExists = true;
        }
    }
    if (InvalidClientExists)
        _deqConnections.erase(std::remove(_deqConnections.begin(), _deqConnections.end(), nullptr), _deqConnections.end());
}

void AServer::SendToClientWithId(const package &msg, const int &id)
{
    for (const auto &client: _deqConnections) {
        if (client && client->IsConnected() && client->userId == id) {
        // if (client && client->GetID() == id) {
            client->Send(msg);
        }
    }
}

void AServer::Update(std::size_t MaxMessages)
{
    std::size_t MessageCount = 0;
    while (MessageCount < MaxMessages && !_QMessagesIn.empty()) {
        auto msg = _QMessagesIn.pop_front();
        OnMessage(msg.remote, msg.msg);
        MessageCount += 1;
    }
}