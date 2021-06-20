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

void Toy::speak(const std::string &statement)
{
    std::cout << this->getName() << " \"" << statement << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Toy &toy)
{
    s << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return s;
}

Toy &operator<<(Toy &toy, std::string str)
{
    toy.setData(str);
    return toy;
}

Toy::~Toy()
{
}
