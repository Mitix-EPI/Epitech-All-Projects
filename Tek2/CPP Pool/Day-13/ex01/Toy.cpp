/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->picture = new Picture;
    this->type = BASIC_TOY;
    this->name = "toy";
}

Toy::Toy(const ToyType &type, const std::string name, const std::string filename)
{
    this->picture = new Picture(filename);
    this->type = type;
    this->name = name;
}

Toy::Toy(const Toy &oldToy)
{
    this->picture = new Picture;
    this->name = oldToy.name;
    this->type = oldToy.type;
    if (oldToy.picture) {
        this->picture->data = oldToy.picture->data;
    } else {
        this->picture->data = "";
    }
}

Toy &Toy::operator=(const Toy &oldToy)
{
    this->picture = new Picture;
    this->name = oldToy.name;
    this->type = oldToy.type;
    if (oldToy.picture) {
        this->picture->data = oldToy.picture->data;
    } else {
        this->picture->data = "";
    }
    return *this;
}

Toy::~Toy()
{
    if (this->picture)
        delete this->picture;
}
