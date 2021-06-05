/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** IDisplayModule
*/

#include "UtilityClasses.hpp"
#include "IGameModule.hpp"
#include <unordered_map>
#include <vector>
#include <string>

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void open(void) = 0;
        virtual void display(arcade::IGameModule *) = 0;
        virtual Vector2i getEventClick(void) = 0;
        virtual char getKeyboardEvent(void) = 0;
        virtual std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs) = 0;
        virtual void close(void) = 0;
        virtual bool forceExitPoint(void) = 0;
        virtual void changeGame(void) = 0;
    protected:
    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */