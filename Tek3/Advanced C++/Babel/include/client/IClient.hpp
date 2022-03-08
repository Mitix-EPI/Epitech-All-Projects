/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** IClient
*/

#ifndef ICLIENT_HPP_
#define ICLIENT_HPP_

#include "commons/common.h"
#include "commons/Package.hpp"
#include "commons/TsQueue.hpp"
#include "commons/ownedPackage.hpp"
#include "commons/Connection.hpp"

class IClient {
    public:
        virtual ~IClient() = 0;
        virtual bool Connect(const std::string &host, const int port) = 0;
        virtual void Disconnect(void) = 0;
        virtual bool IsConnected(void) = 0;
        virtual void Send(const package &msg) = 0;
        virtual TsQueue<ownedPackage> &getQMessages(void) = 0;
        virtual void update(void) = 0;
};

#endif /* !ICLIENT_HPP_ */