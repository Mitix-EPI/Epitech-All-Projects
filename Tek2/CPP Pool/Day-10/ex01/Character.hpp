/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
        Character(const std::string &name)
        {
            _ap = 40;
            _name = name;
            _weapon = nullptr;
        }
        ~Character()
        {
        }
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);

        std::string const &getName(void) const { return _name; }
        int getAP(void) const { return _ap; }
        std::string const &getWeaponName(void) const { return _weapon->getName(); }
        bool isWeaponEquiped(void) const { if (_weapon) return true; return false; }

    protected:
    private:
        std::string _name;
        int _ap;
        AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &s, const Character &d);

#endif /* !CHARACTER_HPP_ */
