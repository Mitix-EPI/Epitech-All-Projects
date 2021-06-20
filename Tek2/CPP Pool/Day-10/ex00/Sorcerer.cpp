/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

std::ostream &operator<<(std::ostream &s, const Sorcerer &d)
{
    s << "I am " << d.getName() << ", " << d.getTitle() << ", and I like ponies!" << std::endl;
    return s;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}
