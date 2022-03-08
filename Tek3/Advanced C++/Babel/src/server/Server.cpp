/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Server
*/

#include "server/Server.hpp"

Server::Server(int port) : AServer(port), _myDB("babel.db")
{
    this->_userService.createTableIfNotExists(&(this->_myDB));
    this->_messageService.createTableIfNotExists(&(this->_myDB));
    this->initUsersList();
}

bool Server::OnClientConnect(std::shared_ptr<Connection> client)
{
    package msg;
    msg.header.id = MsgTypes::ServerAccept;
    client->Send(msg);
    return true;
}

void Server::OnClientDisconnect(std::shared_ptr<Connection> client)
{
    std::cout << "Removing client [" << client->GetID() << "]" << std::endl;
    updateStatusUserByUserId(client->userId, Babel::Common::UserState::OFFLINE);
    this->notifyUsersStatus(Babel::Common::UserState::OFFLINE, client->userId, client);
}

void Server::OnMessage(std::shared_ptr<Connection> client, package &msg)
{
    switch (msg.header.id) {
        case MsgTypes::FirstConnection :
        {
            OnClientFirstConnection(client, msg);
        }
        break;
        case MsgTypes::Authentification :
        {
            OnAuth(client, msg);
        }
        break;
        case MsgTypes::AuthResult :
        {
            getPasswd(client, msg);
        }
        break;
        case MsgTypes::Register :
        {
            registerUser(client, msg);
        }
        break;
        case MsgTypes::Login :
        {
            loginUser(client, msg);
        }
        break;
        case MsgTypes::NotifyStatus :
        {
            std::cout << "Notification Sent" << std::endl;
        }
        break;
        case MsgTypes::Disconnect :
        {
            client->Disconnect();
        }
        break;
        case MsgTypes::SendMessage :
        {
            std::cout << "Send Message" << std::endl;
            sendMessageToUser(client, msg);
        }
        break;
        case MsgTypes::GetMessage :
        {
            retrieveMessagesWithUser(client, msg);
        }
        break;
        case MsgTypes::MessageReceivedNotification :
        {
            std::cout << "Notification Received by user" << std::endl;
        }
        break;
        case MsgTypes::GetContacts :
        {
            retrieveContactList(client, msg);
        }
        break;
        case MsgTypes::NewUserNotification :
        {
            std::cout << "NewUserNotifiation Received by user" << std::endl;
        }
        break;
    }
}

void Server::OnClientFirstConnection(std::shared_ptr<Connection> client, package &msg)
{
    char buffer[MAX_CREDENTIALS_LENGTH] = {0};
    msg >> buffer;
    std::cout << buffer << std::endl;
    std::cout << "New client [" << client->GetID() << "]" << std::endl;
    package msg2;
    msg2.header.id = MsgTypes::FirstConnection;
    client->Send(msg2);
}

void Server::OnAuth(std::shared_ptr<Connection> client, package &msg)
{
    msg >> client->userName;
    std::cout << client->userName << std::endl;
    client->Send(msg);
}

void Server::getPasswd(std::shared_ptr<Connection> client, package &msg)
{
    msg >> client->passWord;
    std::cout << client->passWord << std::endl;
    client->Send(msg);
}

void Server::sendMessageToUser(std::shared_ptr<Connection> client, package &msg)
{
    Babel::Common::SendMessageTransfertInformations infos;
    msg >> infos;
    package msg2;
    std::cout << "[sendMessageToUser]" << std::endl;
    msg2.header.id = MsgTypes::SendMessage;
    MessageSent res;
    res.code = ResponseCode::Valid;
    saveMessage(infos.targetId, client->userId, std::string(infos.message));
    sendMessageReceivedNotification(infos.targetId, client->userId, -1, std::string(infos.message));
    MessagesTransfert transfert;
    transfert.receiverId = infos.targetId;
    transfert.senderId = client->userId;
    transfert.messageId = -1;
    std::memcpy(&transfert.message, std::string(infos.message).c_str(), std::string(infos.message).size());
    res.msg = transfert;
    msg2 << res;
    client->Send(msg2);
}

void Server::sendMessageReceivedNotification(const int &receiverId, const int &senderId, const int &msgId, const std::string &message)
{
    std::cout << "[sendMessageReceivedNotification]" << std::endl;
    package payload;
    payload.header.id = MsgTypes::MessageReceivedNotification;

    // char cmess[MAX_MESSAGE_LENGTH] = { 0 };

    MessageReceivedNotif msg;
    msg.code = ResponseCode::Valid;
    msg.msg.receiverId = receiverId;
    msg.msg.senderId = senderId;
    msg.msg.messageId = msgId;
    std::memcpy(&msg.msg.message, message.c_str(), message.length());
    payload << msg;
    SendToClientWithId(payload, receiverId);
}

void Server::saveMessage(const int &receiverId, const int &senderId, const std::string &message)
{
    Babel::Database::Message msg = { messageId: -1, senderId: senderId, receiverId: receiverId, message: message };

    _messageService.addMessage(&_myDB, msg);
}

void Server::retrieveMessagesWithUser(std::shared_ptr<Connection> client, package &msg)
{
    package msg2;
    MessageList res;

    msg2.header.id = MsgTypes::GetMessage;

    Babel::Common::MessageTransfertInformations infos;
    msg >> infos;
    
    std::cout << "targetId is : " << infos.targetId  << "userId is : " << client->userId << std::endl;
    // std::cout << "targetId2 is : " << infos.targetId  << "userId is : " << 1 << std::endl;

    getAllMessagesWithUser(res.messages, client->userId, infos.targetId);
    // getAllMessagesWithUser(res.messages, 1, infos.targetId);
    res.code = ResponseCode::Valid;
    
    for (int i = 0; i < 20 && res.messages[i].messageId != -84; i++)
        std::cout << "msg : " << i << " is : " << std::string(res.messages[i].message) << std::endl;

    msg2 << res;
    client->Send(msg2);

    std::cout << "Enter get Message with user" << std::endl;

}

void Server::registerUser(std::shared_ptr<Connection> client, package &msg)
{
    Response res;
    package msg2;
    msg2.header.id = MsgTypes::Register;

    std::cout << "Enter register server" << std::endl;
    Babel::Common::UserTransfert user;
    msg >> user;
    std::cout << user.name << std::endl;
    std::cout << user.pass << std::endl;
    Babel::Database::UserDB userDB = { -1, "", "" };
    this->_userService.getUserByUsername(&(this->_myDB), userDB, std::string(user.name));
    if (userDB.id > 0) {
        // Error handling same username
        res.code = ResponseCode::Error;
        std::memcpy(&res.msg, "Register Failed", 17);
        msg2 << res;
        std::cout << "Username already used" << std::endl;
        client->Send(msg2);
        return;
    }
    userDB.id = -1;
    userDB.username = std::string(user.name);
    userDB.password = std::string(user.pass);
    this->_userService.addUser(&(this->_myDB), userDB);

    this->_userService.getUserByInformations(&(this->_myDB), userDB, userDB.username, userDB.password);

    std::cout << "[registerUser] id = " << userDB.id << " name = " << userDB.username << " pass = " << userDB.password << std::endl;
    Babel::Common::User usr;

    usr.id = userDB.id;
    usr.username = std::string(userDB.username);
    usr.ip = std::string(""); // TODO
    usr.status = Babel::Common::UserState::OFFLINE;
    this->_usersList.push_back(usr);

    notifyForNewUser(client, usr);

    res.code = ResponseCode::Valid;
    std::memcpy(&res.msg, "Success Register", 17);
    msg2 << res;
    std::cout << "Registered Success" << std::endl;
    client->Send(msg2);
}

void Server::notifyForNewUser(std::shared_ptr<Connection> client, Babel::Common::User usr)
{
    package msg;
    msg.header.id = MsgTypes::NewUserNotification;
    NewUserNotif notif;
    notif.code = ResponseCode::Valid;

    UserContact contact;
    std::memset(&contact, 0, sizeof(contact));
    std::memcpy(&contact.username, usr.username.c_str(), usr.username.size());
    std::memcpy(&contact.ip, "", 0);
    contact.id = usr.id;
    contact.status = Babel::Common::UserState::OFFLINE;

    notif.user = contact;
    msg << notif;

    this->SendToAllClient(msg, client);
}

void Server::loginUser(std::shared_ptr<Connection> client, package &msg)
{
    UserContactList res;
    package msg2;
    msg2.header.id = MsgTypes::Login;

    std::cout << "Enter login server" << std::endl;
    Babel::Common::UserTransfert user;
    msg >> user;
    std::cout << "Login :" << std::endl;
    std::cout << user.name << std::endl;
    std::cout << user.pass << std::endl;
    Babel::Database::UserDB userDB = { -1, "", "" };
    this->_userService.getUserByInformations(&(this->_myDB), userDB, std::string(user.name), std::string(user.pass));
    if (userDB.id < 0) { // and user.name == "" && user.pass == ""
        // Error handling user not found
        res.code = ResponseCode::Error;
        msg2 << res;
        std::cout << "Login Failed" << std::endl;
        client->Send(msg2);
        return;
    }
    client->userId = userDB.id;
    updateUserToUserList(client, userDB, Babel::Common::UserState::ONLINE);

    res.code = ResponseCode::Valid;
    this->getUserContactList(res.users, userDB.id);
    msg2 << res;
    std::cout << "Login Success" << std::endl;
    client->Send(msg2);
}
void Server::retrieveContactList(std::shared_ptr<Connection> client, package &msg)
{
    UserContactList contacts;
    package msg2;
    msg2.header.id = MsgTypes::GetContacts;

    std::cout << "Retrieving contact list" << std::endl;
    getUserContactList(contacts.users, client->userId);
    msg2 << contacts;
    client->Send(msg2);
}

void Server::updateUserToUserList(std::shared_ptr<Connection> client, Babel::Database::UserDB userDB, Babel::Common::UserState state)
{
    bool val = this->updateStatusUserByUserId(userDB.id, state);

    if (val == false) {
        this->addUserToList(client, userDB);
    }
    // Notify all users
    this->notifyUsersStatus(state, userDB.id, client);
}
void Server::notifyUsersStatus(Babel::Common::UserState state, int fromUserId, std::shared_ptr<Connection> client)
{
    StatusResponse res;
    package msg;

    msg.header.id = MsgTypes::NotifyStatus;
    res.code = ResponseCode::Valid;
    res.status = state;
    res.userId = fromUserId;
    msg << res;
    this->SendToAllClient(msg, client);
}
bool Server::updateStatusUserByUserId(int userId, Babel::Common::UserState status)
{
    for (auto it = this->_usersList.begin(); it != this->_usersList.end(); it++) {
        if (it->id == userId) {
            it->status = status;
            return true;
        }
    }
    return false;
}
void Server::addUserToList(std::shared_ptr<Connection> client, Babel::Database::UserDB userDB)
{
    Babel::Common::User user;

    user.id = userDB.id;
    user.username = std::string(userDB.username);
    user.ip = std::string(""); // TODO
    user.status = Babel::Common::UserState::ONLINE;
    this->_usersList.push_back(user);
}

void Server::initUsersList(void)
{
    std::vector<Babel::Database::UserDB> users;

    this->_userService.getAllUsers(&this->_myDB, users);

    for (auto it = users.begin(); it != users.end(); it++) {
        Babel::Common::User user;

        user.id = it->id;
        user.username = std::string(it->username);
        user.ip = std::string("");
        user.status = Babel::Common::UserState::OFFLINE;
        this->_usersList.push_back(user);
    }
}

void Server::getUserContactList(UserContact *users, int userId)
{
    int index = 0;
    std::cout << "[getUserContactList] id = " << userId << std::endl;

    for (const auto &it: _usersList) {
        if (it.id == userId) {
            continue;
        }
        std::cout << "Server : " << it.username << std::endl;
        std::memset(&users[index], 0, sizeof(UserContact));
        std::memcpy(&users[index].username, it.username.c_str(), it.username.size());
        std::cout << "DB : " << std::string(users[index].username) << std::endl;
        std::memcpy(&users[index].ip, it.ip.c_str(), it.ip.size());
        users[index].id = it.id;
        users[index].status = it.status;
        index++;
    }
    users[index].id = -84;
}

void Server::getAllMessagesWithUser(MessagesTransfert *messages, const int &firstId, const int &targetId)
{
    std::vector<Babel::Database::Message> msgs;
    _messageService.getMessagesByInformations(&_myDB, msgs, firstId, targetId);
    int index = 0;

    for (const auto &it : msgs) {
        if (index >= MAX_MESSAGE_LIST_LENGTH - 1)
            break;
        std::memset(&messages[index], 0, sizeof(MessagesTransfert));
        std::memcpy(&messages[index].message, it.message.c_str(), it.message.size());
        messages[index].receiverId = it.receiverId;
        messages[index].senderId = it.senderId;
        messages[index].messageId = it.messageId;
        index++;
    }
    messages[index].messageId = -84;
}