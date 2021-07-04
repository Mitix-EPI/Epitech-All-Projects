/*
** EPITECH PROJECT, 2021
** messenger
** File description:
** header file
*/

#ifndef MESSENGER_HPP_
#define MESSENGER_HPP_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include <iostream>
#include <ostream>

#define handle_error(msg) \
            do { perror(msg); exit(84); } while (0)

class Messenger {
    public:
        Messenger();
        ~Messenger();
        void open(std::string name);
        int receive();
        void send(const char *msg);
        void close();
        char _buffer[1024];

    private:
        mqd_t _mq;
        struct mq_attr _attr;
};

typedef struct mq_s {
    Messenger in;
    Messenger out;
}mq_t;

#endif /* !MESSENGER_HPP_ */