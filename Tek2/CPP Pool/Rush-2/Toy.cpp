/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(std::string &name, const std::string &type = TOY): Object(name, type)
{
    this->_name = name;
    this->_obj = nullptr;
}

Toy::~Toy()
{
}
