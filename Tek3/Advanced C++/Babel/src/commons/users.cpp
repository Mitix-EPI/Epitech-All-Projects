/*
** EPITECH PROJECT, 2021
** users.cpp
** File description:
** users.cpp
*/

#include "commons/users.hpp"

Babel::Common::Users::Users(
        const std::string &username, const std::string &ip,
        const Babel::Common::UserState &state,
        const int &id
    ): _username(username), _ip(ip), _status(state), _userId(id)
{
}

Babel::Common::Users::Users(
    const Babel::Database::UserDB &user,
    const std::string &ip,
    const UserState &state
): _username(user.username), _userId(user.id), _status(state), _ip(ip)
{
}

Babel::Common::Users::~Users()
{
}

std::string Babel::Common::Users::getUsername() const
{
    return _username;
}

std::string Babel::Common::Users::getIP() const
{
    return _ip;
}

Babel::Common::UserState Babel::Common::Users::getStatus() const
{
    return _status;
}

int Babel::Common::Users::getUserId() const
{
    return _userId;
}

void Babel::Common::Users::setUsername(const std::string &username)
{
    _username = username;
}

void Babel::Common::Users::setIP(const std::string &ip)
{
    _ip = ip;
}

void Babel::Common::Users::setStatus(const Babel::Common::UserState &state)
{
    _status = state;
}

void Babel::Common::Users::setId(const int &id)
{
    _userId = id;
}

Babel::Common::User Babel::Common::Users::generateUser()
{
    Babel::Common::User user;
    user.id = _userId;
    user.username = _username;
    user.ip = _ip;
    user.status = _status;

    return user;
}