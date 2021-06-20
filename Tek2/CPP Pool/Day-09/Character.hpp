/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character {
    public:
        Character() { }
        Character(const std::string &name, int level, int strength = 5, int stamina = 5, int intelligence = 5, int spirit = 5, int agility = 5, const std::string _classarg = "Character", const std::string race = "Human", int range = 0)
            : Range((Character::AttackRange)range), _name(name), _level(level), _strength(strength), _stamina(stamina), _intelligence(intelligence), _spirit(spirit), _agility(agility), _class(_classarg), _pv(100), _power(100), _race(race)
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
            std::cout << name << " Created" << std::endl;
        }
        ~Character();

        // getters
        const std::string &getName() const { return _name; }
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

        // setters
        void setLvl(int level) { _level = level; }
        void setPv(int pv) { _pv = pv; }
        void setPower(int power) { _power = power; }
        void setStrength(int strength) { _strength = strength; }
        void setStamina(int stamina) { _stamina = stamina; }
        void setIntelligence(int intelligence) { _intelligence = intelligence; }
        void setSpirit(int spirit) { _spirit = spirit; }
        void setAgility(int agility) { _agility = agility; }

        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);
        void TakeDamage(int damage);

        enum AttackRange {
            CLOSE,
            RANGE,
        };
        AttackRange Range;

    protected:
        std::string _name;
        int _level;
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
        std::string _class;
        int _pv;
        int _power;
        std::string _race;
    private:
};

#endif /* !CHARACTER_HPP_ */
