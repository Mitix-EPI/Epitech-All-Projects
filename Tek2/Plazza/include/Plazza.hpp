/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
#include <regex>
#include <cctype>
#include <sys/wait.h>
#include "Messenger.hpp"
#include "Logfile.hpp"

typedef struct kitchenStatus_s kitchenStatus_t;
typedef struct command_s command_t;
typedef struct cookStatus_s cookStatus_t;

enum status_s {
    AVAILABLE,
    NOT_AVAILABLE
};


enum PizzaType
{
    None = 0,
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    Null = 0,
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

class Plazza {
    public:
        Plazza(size_t multiplier, size_t Cooks, size_t time);
        ~Plazza();

        void getStatus(void);
        std::vector<cookStatus_t> parseStatus(std::string);
        status_s getEnumStatus(std::string arg);
        int runShell(void);
        void createKitchen();
        void handlingCommand(command_t * command);
        bool fillKitchen(command_t *command);
        void sendCommandToKitchen(size_t kitchenI, size_t cookI, size_t cookStatus, PizzaType pizzaType, PizzaSize pizzaSize);
        void checkPizzaFinished();
        void clearMQ(size_t i);

    private:
        size_t _multiplizer;
        size_t _Cooks;
        size_t _time;
        std::vector<mq_t> _mq;
        size_t _kitchen_nbr;
        std::vector<kitchenStatus_t> _kitchenStatus;
};

typedef struct command_s {
    PizzaType pizzaType;
    PizzaSize pizzaSize;
    size_t steps;
    size_t currentStep = 0;
    size_t number;
    bool waiting;
    int status;
} command_t;

typedef struct cookStatus_s {
    enum status_s _current;
    enum status_s _next;
} cookStatus_t;

typedef struct kitchenStatus_s {
    std::vector<cookStatus_t> _cooks;
    bool _closed;
} kitchenStatus_t;

void interactive_shell(void);

#endif /* !PLAZZA_HPP_ */
