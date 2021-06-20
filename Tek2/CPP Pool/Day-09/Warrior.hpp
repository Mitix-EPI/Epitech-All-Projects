/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior: virtual public Character {
    public:
        Warrior() {}
        Warrior(const std::string &name, int level, std::string _weapon = "hammer", int strength = 12, int stamina = 12, int intelligence = 6, int spirit = 5, int agility = 7, const std::string _classarg = "Warrior", const std::string race = "Dwarf", int range = 0)
            : Character(name, level, strength, stamina, intelligence, spirit, agility, _classarg, race, range), weaponName(_weapon)
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
            std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
        }
        ~Warrior();

        std::string getWeaponName() { return weaponName; }

        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);

    protected:
        std::string weaponName;
    private:
};

#endif /* !WARRIOR_HPP_ */
