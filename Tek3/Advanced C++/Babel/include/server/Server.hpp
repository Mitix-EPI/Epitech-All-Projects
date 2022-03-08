/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "server/AServer.hpp"
#include "server/Server.hpp"
#include "commons/Connection.hpp"

class Server : public AServer
{
    public :
        Server(int port);
    protected:
        virtual bool OnClientConnect(std::shared_ptr<Connection> client);
        virtual void OnClientDisconnect(std::shared_ptr<Connection> client);
        virtual void OnMessage(std::shared_ptr<Connection> client, package &msg);
    private :
        void OnClientFirstConnection(std::shared_ptr<Connection> client, package &msg);
        void OnAuth(std::shared_ptr<Connection> client, package &msg);
        void getPasswd(std::shared_ptr<Connection> client, package &msg);
        void sendMessageToUser(std::shared_ptr<Connection> client, package &msg);
        void sendMessageReceivedNotification(const int &receiverId, const int &senderId, const int &msgId, const std::string &message);
        void saveMessage(const int &receiverId, const int &senderId, const std::string &message);
        void retrieveMessagesWithUser(std::shared_ptr<Connection> client, package &msg);
        void registerUser(std::shared_ptr<Connection> client, package &msg);
        void notifyForNewUser(std::shared_ptr<Connection> client, Babel::Common::User usr);
        void loginUser(std::shared_ptr<Connection> client, package &msg);
        void retrieveContactList(std::shared_ptr<Connection> client, package &msg);
        void updateUserToUserList(std::shared_ptr<Connection> client, Babel::Database::UserDB userDB, Babel::Common::UserState state);
        void notifyUsersStatus(Babel::Common::UserState state, int fromUserId, std::shared_ptr<Connection> client);
        bool updateStatusUserByUserId(int userId, Babel::Common::UserState status);
        void addUserToList(std::shared_ptr<Connection> client, Babel::Database::UserDB userDB);
        void initUsersList(void);
        void getUserContactList(UserContact *users, int userId);
        void getAllMessagesWithUser(MessagesTransfert *messages, const int &firstId, const int &targetId);
        
        Babel::Database::MySQLiteDatabase _myDB;
        Babel::Database::UserServices _userService;
        Babel::Database::MessagesServices _messageService;
        std::vector<Babel::Common::User> _usersList;
};


#endif /* !SERVER_HPP_ */
