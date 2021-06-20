/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage > 0)
        _hp -= damage;
}
