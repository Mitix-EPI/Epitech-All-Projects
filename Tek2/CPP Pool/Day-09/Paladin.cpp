/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::~Paladin()
{
}

int Paladin::CloseAttack(void)
{
    return Warrior::CloseAttack();
}

void Paladin::Heal(void)
{
    Priest::Heal();
}

int Paladin::RangeAttack(void)
{
    return Priest::RangeAttack();
}

void Paladin::RestorePower(void)
{
    Warrior::RestorePower();
}

int Paladin::Intercept(void)
{
    return Warrior::RangeAttack();
}
