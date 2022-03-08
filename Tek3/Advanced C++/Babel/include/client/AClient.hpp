/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** AClient
*/

#ifndef ACLIENT_HPP_
#define ACLIENT_HPP_

#include "commons/common.h"
#include "commons/Package.hpp"
#include "commons/TsQueue.hpp"
#include "commons/ownedPackage.hpp"
#include "commons/Connection.hpp"
#include <QObject>

class AClient
{
    public:
        AClient();
        virtual ~AClient();
        bool Connect(const std::string &host, const int port);
        void Disconnect(void);
        bool IsConnected(void);
        void Send(const package &msg);
        TsQueue<ownedPackage> &getQMessages(void);

    protected :
        asio::io_context _context;
        std::thread thrContext;
        asio::ip::tcp::socket _socket;
        std::unique_ptr<Connection> _connection;
    private:
        TsQueue<ownedPackage> _QMessagesIn;
};

#endif /* !ACLIENT_HPP_ */
