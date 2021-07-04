/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Cooks
*/

#include "Cooks.hpp"

Cooks::Cooks()
{
    this->_stepsPizza[1].push_back("doe");
    this->_stepsPizza[2].push_back("doe");
    this->_stepsPizza[2].push_back("tomato");
    this->_stepsPizza[2].push_back("gruyere");
    this->_stepsPizza[2].push_back("ham");
    this->_stepsPizza[2].push_back("mushrooms");
    this->_stepsPizza[4].push_back("doe");
    this->_stepsPizza[4].push_back("tomato");
    this->_stepsPizza[4].push_back("gruyere");
    this->_stepsPizza[4].push_back("steak");
    this->_stepsPizza[8].push_back("doe");
    this->_stepsPizza[8].push_back("tomato");
    this->_stepsPizza[8].push_back("eggplant");
    this->_stepsPizza[8].push_back("goatCheese");
    this->_stepsPizza[8].push_back("chiefLove");
    this->_time = clock();
    this->_startToCook = 0;
    this->_current.currentStep = 0;
    this->_current.number = 0;
    this->_current.pizzaSize = Null;
    this->_current.pizzaType = None;
    this->_current.steps = 0;
    this->_current.waiting = false;
    this->_next.currentStep = 0;
    this->_next.number = 0;
    this->_next.pizzaSize = Null;
    this->_next.pizzaType = None;
    this->_next.steps = 0;
    this->_next.waiting = false;
}

Cooks::~Cooks()
{
}

command_t Cooks::getCurrent(void)
{
    return this->_current;
}

command_t Cooks::getNext(void)
{
    return this->_next;
}

void Cooks::setCurrent(command_t command)
{
    this->_current = command;
    this->_current.waiting = true;
    this->_time = clock();
}

void Cooks::setNext(command_t command)
{
    this->_next = command;
    this->_next.waiting = true;
}

void Cooks::cookPizza(commandData_t *com)
{
    int pos = com->command->pizzaType;
    com->command->status = 1;
    std::map<int, std::vector<std::string>> steps;
    steps[1].push_back("doe");
    steps[1].push_back("doe");
    steps[1].push_back("doe");
    steps[2].push_back("doe");
    steps[2].push_back("tomato");
    steps[2].push_back("gruyere");
    steps[2].push_back("ham");
    steps[2].push_back("mushrooms");
    steps[4].push_back("doe");
    steps[4].push_back("tomato");
    steps[4].push_back("gruyere");
    steps[4].push_back("steak");
    steps[8].push_back("doe");
    steps[8].push_back("tomato");
    steps[8].push_back("eggplant");
    steps[8].push_back("goatCheese");
    steps[8].push_back("chiefLove");
    for (size_t i = 0; i < steps[pos].size(); i++) {
        (*com->_ingredients)[steps[pos][i]]--;
    }
    int multiplier = 0;
    if (pos == 2)
        multiplier = 1 * com->mult;
    if (pos == 1 || pos == 4)
        multiplier = 2 * com->mult;
    if (pos == 8)
        multiplier = 4 * com->mult;
    sleep(multiplier);
    com->command->waiting = false;
    com->command->status = 2;
    // std::cout << "finished pizza" << std::endl;
}

Thread &Cooks::getThread(void)
{
    return this->_thread;
}

void Cooks::setThread(Thread &thread)
{
    this->_thread.swap(thread);
}
