/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** ownedPackage
*/

#ifndef OWNEDPACKAGE_HPP_
#define OWNEDPACKAGE_HPP_

#include "common.h"
#include "Package.hpp"

class Connection;

struct ownedPackage
{
    std::shared_ptr<Connection> remote = nullptr;
    package msg;

    friend std::ostream &operator<<(std::ostream &os, const ownedPackage &msg)
    {
        os << msg.msg;
        return os;
    }
};

#endif /* !OWNEDPACKAGE_HPP_ */