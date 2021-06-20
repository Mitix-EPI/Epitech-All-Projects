/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Victim
*/

#include "Victim.hpp"

std::ostream &operator<<(std::ostream &s, const Victim &d)
{
    s << "I'm " << d.getName() << " and I like otters!" << std::endl;
    return s;
}

void Victim::getPolymorphed(void) const
{
    std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}
