/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::~Hunter()
{
}

int Hunter::CloseAttack(void)
{
    if (this->Range == RANGE || this->getWeaponName() != "sword")
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

void Hunter::Heal(void)
{
    this->Heal();
}

int Hunter::RangeAttack(void)
{
    if (this->getPower() - 25 >= 0) {
        this->setPower(this->getPower() - 25);
        std::cout << this->getName() << " uses his bow" << std::endl;
        return 20 + this->getAgility();
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Hunter::RestorePower(void)
{
    this->setPower(100);
    std::cout << this->getName() << " meditates" << std::endl;
}

void Hunter::TakeDamage(int damage)
{
    Warrior::TakeDamage(damage);
}
