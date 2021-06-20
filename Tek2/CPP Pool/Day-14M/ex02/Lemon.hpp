/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-alexandre.juan
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
        Lemon(std::string name = "lemon", int vitamins = 3);
        ~Lemon();

    protected:
    private:
};

#endif /* !LEMON_HPP_ */
