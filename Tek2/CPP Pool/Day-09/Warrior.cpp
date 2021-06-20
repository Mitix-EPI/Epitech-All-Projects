/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::~Warrior()
{
}

int Warrior::CloseAttack(void)
{
    if (this->Range == RANGE || this->getWeaponName() != "hammer")
        return 0;
    if (this->getPower() - 30 >= 0) {
        this->setPower(this->getPower() - 30);
        std::cout << this->getName() << " strikes with his " << this->getWeaponName() << std::endl;
        return 20 + this->getStrength();
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Warrior::Heal(void)
{
    this->setPv(this->getPv() + 50);
    if (this->getPv() > 100)
        this->setPv(100);
    std::cout << getName() << " takes a potion" << std::endl;
}

int Warrior::RangeAttack(void)
{
    if (this->Range == CLOSE)
        return 0;
    if (this->getPower() - 10 >= 0) {
        this->setPower(this->getPower() - 10);
        std::cout << this->getName() << " intercepts" << std::endl;
        this->Range = CLOSE;
        return 0;
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Warrior::RestorePower(void)
{
    this->setPower(100);
    std::cout << this->getName() << " eats" << std::endl;
}
