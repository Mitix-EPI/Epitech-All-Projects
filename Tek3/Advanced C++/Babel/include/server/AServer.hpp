/*
** EPITECH PROJECT, 2021
** server.hpp
** File description:
** server.hpp
*/

#ifndef ASERVER_HPP_
#define ASERVER_HPP_

#include "commons/common.h"
#include "commons/Package.hpp"
#include "commons/Connection.hpp"
#include "commons/TsQueue.hpp"
#include "commons/ownedPackage.hpp"
#include "IServer.hpp"

class AServer : public IServer
{
    public :
        AServer(int port);
        virtual ~AServer();
        bool Start();
        void Stop();
        void WaitForClientConnection();
        void SendToClient(std::shared_ptr<Connection> client, const package &msg);
        void SendToAllClient(const package &msg, std::shared_ptr<Connection> IgnoreClient = nullptr);
        void Update(std::size_t MaxMessages = -1);
        void SendToClientWithId(const package &msg, const int &id);
        protected:
            TsQueue<ownedPackage> _QMessagesIn;
            std::deque<std::shared_ptr<Connection>> _deqConnections;
            asio::io_context _asioContext;
            std::thread _threadContext;
            asio::ip::tcp::acceptor _asioAcceptor;
            unsigned int _IdCounter = 1;
};

#endif /* !ASERVER_HPP_ */
