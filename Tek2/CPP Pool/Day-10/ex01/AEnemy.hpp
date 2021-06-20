/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <string>
#include <iostream>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type)
        {
            _hp = hp;
            _type = type;
        }
        virtual ~AEnemy();

        virtual void takeDamage(int damage);

        std::string const &getType(void) const { return _type; }
        int getHP(void) const { return _hp; }

        void setHP(int hp) { _hp = hp; }

    protected:
        std::string _type;
        int _hp;
    private:
};

#endif /* !AENEMY_HPP_ */
