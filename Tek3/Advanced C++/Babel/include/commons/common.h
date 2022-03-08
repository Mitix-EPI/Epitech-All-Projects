/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** common
*/

#ifndef COMMON_H_
#define COMMON_H_

#include <memory>
#include <thread>
#include <mutex>
#include <deque>
#include <optional>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include "users.hpp"

namespace Babel {
    namespace Common {
        struct UserTransfert;
        enum UserState : int;
    };
}

#define MAX_CREDENTIALS_LENGTH 40
#define MAX_USERS_LIST_LENGTH 400
#define MAX_MESSAGE_LIST_LENGTH 500
#define MAX_MESSAGE_LENGTH 400

enum class MsgTypes : uint32_t
{
    FirstConnection,
    ServerAccept,
    ServerDeny,
    ServerMessage,
    Authentification,
    AuthResult,
    Register,
    Login,
    NotifyStatus,
    Disconnect,
    SendMessage,
    GetMessage,
    MessageReceivedNotification,
    GetContacts,
    NewUserNotification
};

enum class ResponseCode : uint32_t
{
    Valid,
    Error
};

struct Response {
    ResponseCode code;
    char msg[MAX_CREDENTIALS_LENGTH] = { 0 };
};

struct StatusResponse {
    ResponseCode code;
    Babel::Common::UserState status;
    int userId;
};

struct UserContact {
    char username[MAX_CREDENTIALS_LENGTH] = { 0 };
    char ip[MAX_CREDENTIALS_LENGTH] = { 0 };
    int id;
    Babel::Common::UserState status;
};

struct MessagesTransfert {
    int receiverId;
    int senderId;
    int messageId;
    char message[MAX_MESSAGE_LENGTH] = { 0 };
};

struct MessageList {
    ResponseCode code;
    MessagesTransfert messages[MAX_MESSAGE_LIST_LENGTH];
};

struct UserContactList {
    ResponseCode code;
    UserContact users[MAX_USERS_LIST_LENGTH];
};

struct MessageSent {
    ResponseCode code;
    MessagesTransfert msg;
};

struct NewUserNotif {
    ResponseCode code;
    UserContact user;
};

struct MessageReceivedNotif {
    ResponseCode code;
    MessagesTransfert msg;
};

#endif /* !COMMON_H_ */
