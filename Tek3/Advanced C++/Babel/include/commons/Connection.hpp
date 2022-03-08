/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include "commons/common.h"
#include "commons/TsQueue.hpp"
#include "commons/Package.hpp"
#include "commons/ownedPackage.hpp"

class Connection : public std::enable_shared_from_this<Connection>
{
    public:
        enum class owner
        {
            server,
            client
        };
        Connection(owner parent, asio::io_context &asioContext, asio::ip::tcp::socket socket, TsQueue<ownedPackage> &qIn);
        virtual ~Connection();
        void ConnectToClient(unsigned int uid = 0);
        bool ConnectToServer(const asio::ip::tcp::resolver::results_type &endpoints);
        bool Disconnect();
        bool IsConnected() const;
        bool Send(const package &msg);
        unsigned int GetID() const;
        char userName[MAX_CREDENTIALS_LENGTH] = { 0 };
        char passWord[MAX_CREDENTIALS_LENGTH] = { 0 };
        int userId = -1;
    private:
        void ReadHeader();
        void ReadBody();
        void WriteHeader();
        void WriteBody();
        void AddToIncomingMessageQueue();
    protected:
        asio::ip::tcp::socket _socket;
        asio::io_context &_ioContext;
        TsQueue<package> _QMessagesOut;
        TsQueue<ownedPackage> &_QMessagesIn;
        owner _OwnerType = owner::server;
        unsigned int id = 0;
        package _msgTmpIn;
};


#endif /* !CONNECTION_HPP_ */
