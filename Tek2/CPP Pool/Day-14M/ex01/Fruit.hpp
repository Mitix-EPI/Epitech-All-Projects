/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-alexandre.juan
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>
#include <iostream>

class Fruit {
    public:
        Fruit(std::string name, int vitamins);
        ~Fruit();

        std::string getName(void) const { return _name; }
        int getVitamins(void) const { return _vitamins; }

    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !FRUIT_HPP_ */
