/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "UtilityClasses.hpp"
#include <vector>

class Fruit {
    public:
        Fruit(int index, Vector2i pos);
        ~Fruit() {};

        int _index;
        Vector2i _pos;
    protected:
    private:

};

#endif /* !FRUIT_HPP_ */
