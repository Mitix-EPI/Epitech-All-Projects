/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Client
*/

#include "client/Client.hpp"
#include "commons/users.hpp"

void Client::auth(const std::string &userName)
{
    char name[MAX_CREDENTIALS_LENGTH] = { 0 };
    std::memcpy(&name, userName.c_str(), userName.length());
    package msg;
    msg.header.id = MsgTypes::Authentification;
    msg << name;
    std::cout << name << std::endl;
    Send(msg);
    std::cout << loggedIn << std::endl;
}

void Client::firstConnection(void)
{
    char body[MAX_CREDENTIALS_LENGTH] = { 0 };
    std::memcpy(&body, "First Connection", 17);
    package payload;
    payload.header.id = MsgTypes::FirstConnection;
    payload << body;
    std::cout << body << std::endl;
    Send(payload);
    std::cout << "Try to established connection to server" << std::endl;
}

void Client::sendPasswd(const std::string &passWord, package &msg)
{
    char pass[MAX_CREDENTIALS_LENGTH] = { 0 };
    std::memcpy(&pass, passWord.c_str(), passWord.length());
    std::cout << pass << std::endl;
    msg.header.id = MsgTypes::AuthResult;
    msg << pass;
    Send(msg);
}

void Client::authRes(package msg)
{
    loggedIn = 1;
    std::cout << loggedIn << std::endl;
}

void Client::registerUser(const std::string &userName, const std::string &passWord)
{
    Babel::Common::UserTransfert user;
    std::memcpy(&(user.name), userName.c_str(), userName.size());
    std::memcpy(&(user.pass), passWord.c_str(), passWord.size());
    package payload;
    payload.header.id = MsgTypes::Register;
    payload << user;
    Send(payload);
    std::cout << "Try to register user to server db" << std::endl;
}

void Client::loginUser(const std::string &userName, const std::string &passWord)
{
    Babel::Common::UserTransfert user;
    std::memcpy(&(user.name), userName.c_str(), userName.size());
    std::memcpy(&(user.pass), passWord.c_str(), passWord.size());
    package payload;
    payload.header.id = MsgTypes::Login;
    payload << user;
    Send(payload);
    std::cout << "Try to login" << std::endl;
}

void Client::disconnect(void)
{
    package payload;
    payload.header.id = MsgTypes::Disconnect;
    payload << "";
    Send(payload);
    Disconnect();
    std::cout << "Try to disconnect" << std::endl;
}

void Client::emitRegisterSignal(bool res)
{
    emit registerSignal(res);
}

void Client::emitLoginSignal(bool res)
{
    emit loginSignal(res);
}

void Client::emitUserSignal(UserContact user)
{
    emit userSignal(user);
}

void Client::getMessageWithUser(const int &secondId)
{
    package payload;
    Babel::Common::MessageTransfertInformations infos = { targetId: secondId };

    payload.header.id = MsgTypes::GetMessage;
    payload << infos;
    Send(payload);
    std::cout << "Trying to retrieve messages between with " << secondId << std::endl;
}

void Client::emitMessageSignal(bool res)
{
    emit messageSignal(res);
}

void Client::emitMessageReceiveSignal(MessagesTransfert mess)
{
    emit messageReceiveSignal(mess);
}
void Client::sendMessage(const std::string &message, const int &receiverId)
{
    package payload;
    Babel::Common::SendMessageTransfertInformations infos;
    infos.targetId = receiverId;
    std::memcpy(&(infos.message), message.c_str(), message.size());
    // std::memcpy(&(user.pass), passWord.c_str(), passWord.size());
    payload.header.id = MsgTypes::SendMessage;
    payload << infos;
    Send(payload);
    std::cout << "Trying to send message to " << receiverId << std::endl;
}

void Client::getContactList(void)
{
    package payload;
    payload.header.id = MsgTypes::GetContacts;
    payload << "Get";
    Send(payload);
    std::cout << "Trying to get contact list" << std::endl;
}

void Client::emitStatusSignal(StatusResponse res)
{
    emit statusSignal(res);
}

void Client::update(void)
{
    if (!getQMessages().empty()) {
        auto msg = getQMessages().pop_front().msg;
        switch(msg.header.id)
        {
            case MsgTypes::ServerAccept:
            {
                std::string userName{"Hello"};
                firstConnection();
                // getMessageWithUser(3);
                // sendMessage("salut gros bg comment ça va ?", 3);
            }
            break;
            case MsgTypes::FirstConnection:
            {
                std::cout << "Connection established" << std::endl;
            }
            break;
            case MsgTypes::Register:
            {
                Response res;
                msg >> res;
                if (res.code == ResponseCode::Error) {
                    std::cout << "Error register" << std::endl;
                    emitRegisterSignal(false);
                } else {
                    std::cout << res.msg << std::endl;
                    emitRegisterSignal(true);
                }
            }
            break;
            case MsgTypes::Login:
            {
                UserContactList res;
                msg >> res;
                if (res.code == ResponseCode::Error) {
                    std::cout << "Error Login" << std::endl;
                    emitLoginSignal(false);
                } else {
                    std::cout << "Login Success" << std::endl;
                    emitLoginSignal(true);
                    StatusResponse res;
                    emitStatusSignal(res);

                    // for (int i = 0; i < MAX_USERS_LIST_LENGTH && res.users[i].id != -84; i++) {
                    //     std::cout << "Contact : " << std::string(res.users[i].username) << std::endl;
                    //     emitUserSignal(res.users[i]);
                    // }
                }
            }
            break;
            case MsgTypes::NotifyStatus :
            {
                std::cout << "NotifyStatus" << std::endl;
                StatusResponse res;
                msg >> res;

                emitStatusSignal(res);
                package payload;
                payload.header.id = MsgTypes::NotifyStatus;
                payload << "OK";
                Send(payload);
            }
            break;
            case MsgTypes::Authentification :
            {
                sendPasswd("World", msg);
            }
            break;
            case MsgTypes::AuthResult :
            {
                authRes(msg);
            }
            break;
            case MsgTypes::Disconnect :
            {
                std::cout << "Disconnect" << std::endl;
            }
            break;
            case MsgTypes::GetMessage :
            {
                std::cout << "getMessage" << std::endl;
    
                MessageList res;
                msg >> res;
                if (res.code == ResponseCode::Error) {
                    std::cout << "Error retrieving message" << std::endl;
                    emitMessageSignal(false);
                } else {
                    emitMessageSignal(true);
                    for (int i = 0; i < MAX_MESSAGE_LIST_LENGTH && res.messages[i].messageId != -84; i++) {
                        std::cout << "Message from : " << res.messages[i].senderId << " to " << res.messages[i].receiverId << " is : " << std::string(res.messages[i].message) << std::endl;
                        emitMessageReceiveSignal(res.messages[i]);
                    }
                }
            }
            break;
            case MsgTypes::SendMessage :
            {
                MessageSent sent;
                msg >> sent;
                std::cout << "Sent : " << sent.msg.message << " to " << sent.msg.receiverId << std::endl;
                emitMessageReceiveSignal(sent.msg);
            }
            break;
            case MsgTypes::MessageReceivedNotification :
            {
                package payload;
                payload.header.id = MsgTypes::MessageReceivedNotification;
                payload << "OK";

                MessageReceivedNotif rcvMessage;
                msg >> rcvMessage;

                std::cout << "received : " << std::string(rcvMessage.msg.message) << " from : " << rcvMessage.msg.senderId << std::endl;
                emitMessageReceiveSignal(rcvMessage.msg);
                Send(payload);
            }
            break;
            case MsgTypes::GetContacts :
            {
                // package payload;
                // payload.header.id = MsgTypes::GetContacts;
                // payload << "OK";

                UserContactList contacts;
                msg >> contacts;
                for (int i = 0; i < MAX_USERS_LIST_LENGTH && contacts.users[i].id != -84; i++) {
                    std::cout << "Contact : " << std::string(contacts.users[i].username) << std::endl;
                    emitUserSignal(contacts.users[i]);
                }
                // Send(payload);
            }
            break;
            case MsgTypes::NewUserNotification :
            {
                package payload;
                payload.header.id = MsgTypes::NewUserNotification;
                payload << "OK";

                NewUserNotif newUser;
                msg >> newUser;
                std::cout << "new user : " << newUser.user.username << "with id : " << newUser.user.id << std::endl;

                StatusResponse res;
                emitStatusSignal(res);

                Send(payload);
            }
        }
    }
}