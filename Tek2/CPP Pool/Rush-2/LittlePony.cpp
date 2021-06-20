/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string name) : Toy(name, PONY)
{
    this->_name = name;
}

void LittlePony::isTaken(void) const
{
    std::cout << "yo man" << std::endl;
}

LittlePony::~LittlePony()
{
}

std::ostream &operator<<(std::ostream &s, const LittlePony &teddy)
{
    s << "I'm " << teddy.getName() << " and I'm a little pony!" << std::endl;
    return s;
}
