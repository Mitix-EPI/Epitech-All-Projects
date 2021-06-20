/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"
#include "Character.hpp"

class Hunter : virtual protected Warrior {
    public:
        Hunter(const std::string &name, int level, std::string _weapon = "sword", int strength = 9, int stamina = 9, int intelligence = 5, int spirit = 6, int agility = 25, std::string class_arg = "Hunter", std::string race = "Elf", int range_arg = 0)
        : Character(name, level, strength, stamina, intelligence, spirit, agility, class_arg, race, 0), Warrior(name, level, _weapon, strength, stamina, intelligence, spirit, agility, class_arg, race, 0)
        {
            std::cout << name << " is born from a tree" << std::endl;
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
        ~Hunter();

        // Getters
        int getLvl() const { return _level; }
        int getPv() const { return _pv; }
        int getPower() const { return _power; }
        std::string getRace() const { return _race; }
        std::string getClass() const { return _class; }
        int getStrength() const { return _strength; }
        int getStamina() const { return _stamina; }
        int getIntelligence() const { return _intelligence; }
        int getSpirit() const { return _spirit; }
        int getAgility() const { return _agility; }

        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);
        void TakeDamage(int damage);

    protected:
    private:
};

#endif /* !HUNTER_HPP_ */
