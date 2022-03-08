/*
** EPITECH PROJECT, 2021
** users.hpp
** File description:
** users.hpp
*/

#ifndef USERS_HPP_
#define USERS_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "server/database/database.hpp"
#include "common.h"

#define MAX_CREDENTIALS_LENGTH 40
#define MAX_MESSAGE_LENGTH 400

namespace Babel
{
    namespace Common
    {
        enum UserState: int {
            OFFLINE,
            INCALL,
            ONLINE,
            UNKNOWN,
        };

        struct Messages {
            int receiverId;
            int senderId;
            int messageId;
            std::string message;
        };

        struct User {
            int id;
            std::string username;
            std::string ip;
            UserState status;
        };

        struct UserTransfert {
            char name[MAX_CREDENTIALS_LENGTH] = { 0 };
            char pass[MAX_CREDENTIALS_LENGTH] = { 0 };
        };

        struct MessageTransfertInformations {
            int targetId;
        };

        struct SendMessageTransfertInformations {
            int targetId;
            char message[MAX_MESSAGE_LENGTH] = { 0 };
        };

        struct ReceiveMessageTransfert {
            int receivedFromId;
            char message[MAX_MESSAGE_LENGTH] = { 0 };
        };

        class Users {
            public:
                Users(const std::string &username = "",
                    const std::string &ip = "",
                    const UserState &state = UNKNOWN,
                    const int &id = -1);
                Users(
                    const Babel::Database::UserDB &user,
                    const std::string &ip = "",
                    const UserState &state = UNKNOWN);
                ~Users();
                std::string getUsername() const;
                std::string getIP() const;
                UserState getStatus() const;
                int getUserId() const;
                void setUsername(const std::string &name);
                void setIP(const std::string &id);
                void setStatus(const UserState &state);
                void setId(const int &id);
                User generateUser();
            protected:
            private:
                std::string _username;
                std::string _ip;
                UserState _status = UNKNOWN;
                int _userId;
        };
    }
}


#endif /* !USERS_HPP_ */
