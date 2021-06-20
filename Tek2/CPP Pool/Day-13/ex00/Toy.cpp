/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->picture = Picture();
    this->type = BASIC_TOY;
    this->name = "toy";
}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
{
    this->picture = Picture(filename);
    this->type = type;
    this->name = name;
}

Toy::~Toy()
{
}
