/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <vector>
#include <ctime>
#include <future>
#include <utility>
#include "Cooks.hpp"
#include "Plazza.hpp"
#include "Messenger.hpp"
#include "Thread_pool.hpp"

class Kitchen {
    public:
        Kitchen(int mult, int cooksNum, int time);
        ~Kitchen();
        std::string returnKitchen(void);
        bool acceptNewPizza(command_t command);
        void timeSinceInactivity(void);
        void addIngredients(void);
        void parseCookCommand(std::string buffer);
        void sendFinishedCommand(command_t *command);
        void run(void);
        Kitchen operator<<(Kitchen);
        Kitchen operator>>(Kitchen);
        void clearMQ();
        int getId(void);
        void setId(int);
        mq_t getMq(void);
        void setMq(mq_t);
        mq_t _mq;
    private:
        std::vector<Cooks *> _cooks;
        std::vector<command_t *> _commands;
        std::map<std::string, int> _ingredients;
        clock_t _time;
        clock_t _timeRefill;
        int _id;
        int _mult;
        int _timeIngredients;
        int _posCommands;
        Thread_pool *_pool;
};

#endif /* !Kitchen_HPP_ */
