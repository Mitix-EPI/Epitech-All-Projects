/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Encapsulation
*/

#include "Encapsulation.hpp"

Encapsulation::Encapsulation()
{
}

IDisplayModule *Encapsulation::initGraph(void *handle)
{
    IDisplayModule *res = reinterpret_cast<IDisplayModule *(*)()>(dlsym(handle, "initDisplay"))();

    if (dlerror())
        errorDisplay(4, "Error entryPoint Graph lib");
    return res;
}

arcade::IGameModule *Encapsulation::initGame(void *handle)
{
    arcade::IGameModule *res = reinterpret_cast<arcade::IGameModule *(*)()>(dlsym(handle, "initGame"))();

    if (dlerror())
        errorDisplay(4, "Error entryPoint Graph lib");
    return res;
}

Encapsulation::~Encapsulation()
{
}
