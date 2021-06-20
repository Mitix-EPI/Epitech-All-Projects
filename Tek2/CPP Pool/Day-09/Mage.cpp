/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::~Mage()
{
}

int Mage::CloseAttack(void)
{
    if (this->Range == RANGE)
        return 0;
    if (this->getPower() - 10 >= 0) {
        this->setPower(this->getPower() - 10);
        std::cout << this->getName() << " blinks" << std::endl;
        this->Range = RANGE;
        return 0;
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Mage::Heal(void)
{
    this->setPv(this->getPv() + 50);
    if (this->getPv() > 100)
        this->setPv(100);
    std::cout << getName() << " takes a potion" << std::endl;
}

int Mage::RangeAttack(void)
{
    if (this->getPower() - 25 >= 0) {
        this->setPower(this->getPower() - 25);
        std::cout << this->getName() << " launches a fire ball" << std::endl;
        return 20 + this->getSpirit();
    } else {
        std::cout << this->getName() << " out of power" << std::endl;
        return 0;
    }
}

void Mage::RestorePower(void)
{
    this->setPower(this->getPower() + 50 + this->getIntelligence());
    if (this->getPower() > 100)
        this->setPower(100);
    std::cout << this->getName() << " takes a mana potion" << std::endl;
}