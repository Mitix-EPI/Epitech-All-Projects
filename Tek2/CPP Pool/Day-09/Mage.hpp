/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage: virtual public Character {
    public:
        Mage() {};
        Mage(const std::string &name, int level, int strength = 6, int stamina = 6, int intelligence = 12, int spirit = 11, int agility = 7, const std::string _classarg = "Mage", const std::string race = "Gnome", int range = 0)
            : Character(name, level, strength, stamina, intelligence, spirit, agility, _classarg, race, range)
        {
            _name = name;
            _level = level;
            _strength = strength;
            _stamina = stamina;
            _intelligence = intelligence;
            _spirit = spirit;
            _agility = agility;
            _class = _classarg;
            _race = race;
            Range = (AttackRange)range;
            _power = 100;
            _pv = 100;
            std::cout << name << " teleported" << std::endl;
        }
        ~Mage();

        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);

    protected:
    private:
};

#endif /* !MAGE_HPP_ */
