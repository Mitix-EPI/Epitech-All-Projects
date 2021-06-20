/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <string>
#include <iostream>

class AWeapon {
    public:
        AWeapon(const std::string &name, int apcost, int damage)
        {
            _name = name;
            _apcost = apcost;
            _damage = damage;
        }
        virtual ~AWeapon();
        std::string const &getName() const { return _name; }
        int getAPCost(void) const { return _apcost; };
        int getDamage(void) const { return _damage; };
        virtual void attack() const = 0;

    protected:
    private:
        std::string _name;
        int _apcost;
        int _damage;
};

#endif /* !AWEAPON_HPP_ */
