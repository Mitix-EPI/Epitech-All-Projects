/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Character
*/

#include "Character.hpp"

Character::~Character()
{
}

int Character::CloseAttack(void)
{
    if (this->Range == RANGE)
        return 0;
    if (this->getPower() - 10 >= 0) {
        this->setPower(this->getPower() - 10);
        std::cout << this->getName() << " strikes with a wooden stick" << std::endl;
        return 10 + this->getStrength();
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Character::Heal(void)
{
    this->setPv(this->getPv() + 50);
    if (this->getPv() > 100)
        this->setPv(100);
    std::cout << getName() << " takes a potion" << std::endl;
}

int Character::RangeAttack(void)
{
    if (this->getPower() - 10 >= 0) {
        this->setPower(this->getPower() - 10);
        std::cout << this->getName() << " tosses a stone" << std::endl;
        return 5 + this->getStrength();
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Character::RestorePower(void)
{
    this->setPower(100);
    std::cout << this->getName() << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (damage >= this->getPv()) {
        std::cout << this->getName() << " out of combat" << std::endl;
    } else {
        this->setPv(this->getPv() - damage);
        std::cout << this->getName() << " takes " << damage << " damage" << std::endl;
    }
}
