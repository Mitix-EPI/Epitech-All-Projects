/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Character
*/

#include "Character.hpp"

void Character::recoverAP(void)
{
    if (_ap - 10 <= 40)
        _ap += 10;
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (_weapon && this->getAP() >= _weapon->getAPCost()) {
        this->_ap -= _weapon->getAPCost();
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();
        enemy->takeDamage(_weapon->getDamage());
        if (enemy->getHP() <= 0)
            delete enemy;
    }
}

std::ostream &operator<<(std::ostream &s, const Character &d)
{
    if (d.isWeaponEquiped()) {
        s << d.getName() << " has " << d.getAP() << " AP and wields a " << d.getWeaponName() << std::endl;
    } else {
        s << d.getName() << " has " << d.getAP() << " AP and is unarmed" << std::endl;
    }
    return s;
}
