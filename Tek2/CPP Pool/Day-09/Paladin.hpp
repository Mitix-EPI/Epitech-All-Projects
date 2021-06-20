/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : virtual public Warrior, virtual public Priest {
    public:
        Paladin() {}
        Paladin(const std::string &name, int level, std::string _weapon = "hammer", int strength = 9, int stamina = 10, int intelligence = 10, int spirit = 10, int agility = 2, std::string class_arg = "Paladin", std::string race = "Human", int range_arg = 0)
            : Character(name, level, strength, stamina, intelligence, spirit, agility, class_arg, race, 0), Warrior(name, level, _weapon, strength, stamina, intelligence, spirit, agility, class_arg, race, 0), Mage(name, level, strength, stamina, intelligence, spirit, agility, class_arg, race, range_arg), Priest(name, level, strength, stamina, intelligence, spirit, agility, class_arg, race, range_arg)
        {
            std::cout << "the light falls on " << name << std::endl;
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
        }
        ~Paladin();

        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);
        int Intercept(void);

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
