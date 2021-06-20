/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-alexandre.juan
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name = "lemon", int vitamins = 3)
{
    this->_name = name;
    this->_vitamins = vitamins;
}

Fruit::~Fruit()
{
}
