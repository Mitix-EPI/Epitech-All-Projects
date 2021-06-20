/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string name): Toy(name, TED)
{
    this->_name = name;
}

void Teddy::isTaken(void) const
{
    std::cout << "gra hu" << std::endl;
}

Teddy::~Teddy()
{
}

std::ostream &operator<<(std::ostream &s, const Teddy &teddy)
{
    s << "I'm " << teddy.getName() << " and I'm a teddy bear!" << std::endl;
    return s;
}
