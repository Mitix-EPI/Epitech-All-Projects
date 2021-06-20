/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** SuperMutant
*/

#include "SuperMutant.hpp"

void SuperMutant::takeDamage(int damage)
{
    if (damage > 0)
        _hp -= (damage - 3);
}
