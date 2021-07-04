/*
** EPITECH PROJECT, 2021
** Messenger
** File description:
** mq
*/

#include "Messenger.hpp"

Messenger::Messenger()
{
    _attr.mq_flags = 0;
    _attr.mq_maxmsg = 10;
    _attr.mq_msgsize = 1024;
    _attr.mq_curmsgs = 0;
}

Messenger::~Messenger()
{
}

void Messenger::open(std::string name)
{
    _mq = mq_open(name.c_str(), O_CREAT | O_RDWR | O_NONBLOCK, 0644, &_attr);
    if (_mq < 0)
        handle_error("Error on opening message queue");
}

int Messenger::receive()
{
    int bytes_read;

    memset(_buffer, 0, 1024);
    bytes_read = mq_receive(_mq, _buffer, sizeof(_buffer), NULL);
    // if (bytes_read < 0)
    //     std::cout << "Error on reading message queue" << std::endl;
    return bytes_read;
}

void Messenger::close()
{
    if (mq_close(_mq) < 0)
        handle_error("Error on closing the message queue");
}

void Messenger::send(const char *msg)
{
    int ret;

    ret = mq_send(_mq, msg, strlen(msg), 0);
    if (ret < 0)
        handle_error("Error on sending message");
}
