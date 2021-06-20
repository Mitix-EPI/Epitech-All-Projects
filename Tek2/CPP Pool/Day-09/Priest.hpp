/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : virtual public Mage {
    public:
        Priest() {}
        Priest(const std::string &name, int level, int strength = 4, int stamina = 4, int intelligence = 42, int spirit = 21, int agility = 2, std::string class_arg = "Priest", std::string race = "Orc", int range_arg = 0)
            : Character(name, level, strength, stamina, intelligence, spirit, agility, class_arg, race, range_arg), Mage(name, level, strength, stamina, intelligence, spirit, agility, class_arg, race, range_arg)
        {
            _name = name;
            _level = level;
            _strength = strength;
            _stamina = stamina;
            _intelligence = intelligence;
            _spirit = spirit;
            _agility = agility;
            _class = class_arg;
            _race = race;
            Range = (AttackRange)range_arg;
            _power = 100;
            _pv = 100;
            std::cout << name << " enters in the order" << std::endl;
        }
        ~Priest();

        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
