/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Encapsulation
*/


#ifndef ENCAPSULATION_HPP_
#define ENCAPSULATION_HPP_

class IDisplayModule;

namespace arcade {
class IGameModule;
};


#include <vector>
#include <string>
#include <dlfcn.h>
#include "./CoreModule.hpp"
#include "./UtilityClasses.hpp"

class Encapsulation {
    public:
        Encapsulation();
        ~Encapsulation();

        IDisplayModule *initGraph(void *handle);
        arcade::IGameModule *initGame(void *handle);

    protected:
    private:
};

#endif /* !ENCAPSULATION_HPP_ */
