/*
** EPITECH PROJECT, 2021
** client.hpp
** File description:
** client.hpp
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "commons/common.h"
#include "commons/Package.hpp"
#include "commons/TsQueue.hpp"
#include "commons/ownedPackage.hpp"
#include "commons/Connection.hpp"
#include "client/AClient.hpp"

class Client : public QObject, public AClient
{
    Q_OBJECT

    public :
        void auth(const std::string &userName);
        void firstConnection(void);
        void sendPasswd(const std::string &passWord, package &msg);
        void authRes(package msg);
        void registerUser(const std::string &userName, const std::string &passWord);
        void loginUser(const std::string &userName, const std::string &passWord);
        void disconnect(void);
        void getMessageWithUser(const int &targetId);
        void sendMessage(const std::string &message, const int &receiverId);
        void getContactList(void);
        void update(void);

        void emitRegisterSignal(bool res);
        void emitLoginSignal(bool res);
        void emitUserSignal(UserContact user);
        void emitMessageSignal(bool res);
        void emitMessageReceiveSignal(MessagesTransfert mess);
        void emitStatusSignal(StatusResponse res);
    private :
        int loggedIn = 0; 

    signals:
        void registerSignal(bool res);
        void loginSignal(bool res);
        void messageSignal(bool res);
        void userSignal(UserContact user);
        void messageReceiveSignal(MessagesTransfert mess);
        void statusSignal(StatusResponse res);
};

// class AClient
// {
//     public :
//         AClient() : _socket(_context)
//         {
//         }
//         virtual ~AClient()
//         {
//             Disconnect();
//         }
//         bool Connect(const std::string &host, const int port)
//         {
//             try
//             {

//                 asio::ip::tcp::resolver resolver(_context);
//                 asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));
//                 _connection = std::make_unique<Connection>(Connection::owner::client, _context, asio::ip::tcp::socket(_context), _QMessagesIn);
//                 _connection->ConnectToServer(endpoints);
//                 thrContext = std::thread([this]() {_context.run();});

//             }
//             catch(const std::exception& e)
//             {
//                 std::cerr << "Client Exeption: " << e.what() << std::endl;
//             }
            
//             return false;
//         }

//         void Disconnect(void)
//         {
//             if (IsConnected())
//                 _connection->Disconnect();
//             _context.stop();
//             if (thrContext.joinable())
//                 thrContext.join();
//             _connection.release();
//         }

//         bool IsConnected(void)
//         {
//             if (_connection)
//                 return _connection->IsConnected();
//             return false;
//         }

//         void Send(const package &msg)
//         {
//             if (IsConnected())
//                 _connection->Send(msg);
//         }

//         TsQueue<ownedPackage> &getQMessages(void)
//         {
//             return _QMessagesIn;
//         }

//     protected :
//         asio::io_context _context;
//         std::thread thrContext;
//         asio::ip::tcp::socket _socket;
//         std::unique_ptr<Connection> _connection;
//     private:
//         TsQueue<ownedPackage> _QMessagesIn;
// };

#endif /* !CLIENT_HPP_ */
