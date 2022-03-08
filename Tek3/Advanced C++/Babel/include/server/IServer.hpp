/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** IServer
*/

#ifndef ISERVER_HPP_
#define ISERVER_HPP_

#include "commons/common.h"
#include "commons/Package.hpp"
#include "commons/Connection.hpp"
#include "commons/TsQueue.hpp"
#include "commons/ownedPackage.hpp"

class IServer {
    public:
        virtual ~IServer() = default;
        virtual bool Start() = 0;
        virtual void Stop() = 0;
        virtual void WaitForClientConnection() = 0;
        virtual void SendToClient(std::shared_ptr<Connection> client, const package &msg) = 0;
        virtual void SendToAllClient(const package &msg, std::shared_ptr<Connection> IgnoreClient = nullptr) = 0;
        virtual void Update(std::size_t MaxMessages = -1) = 0;
        virtual void SendToClientWithId(const package &msg, const int &id) = 0;
    protected:
        virtual bool OnClientConnect(std::shared_ptr<Connection> client) = 0;
        virtual void OnClientDisconnect(std::shared_ptr<Connection> client) = 0;
        virtual void OnMessage(std::shared_ptr<Connection> client, package &msg) = 0;
};

#endif /* !ISERVER_HPP_ */
