/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Cooks
*/

#ifndef COOKS_HPP_
#define COOKS_HPP_

#include <ctime>
#include <memory>
#include "Plazza.hpp"
#include "Thread.hpp"

typedef struct commandData_s{
    std::map<std::string, int> *_ingredients;
    int mult;
    command_t *command;
}commandData_t;

class Cooks {
    public:
        Cooks();
        ~Cooks();
        static void cookPizza(commandData_t *com);
        command_t getCurrent(void);
        command_t getNext(void);
        void setCurrent(command_t command);
        void setNext(command_t command);
        Thread &getThread(void);
        void setThread(Thread &);
    private:
        Thread _thread;
        command_t _current;
        command_t _next;
        std::vector<command_t> _done;
        std::map<int, std::vector<std::string>> _stepsPizza;
        clock_t _time;
        int _startToCook;
};

#endif /* !COOKS_HPP_ */
