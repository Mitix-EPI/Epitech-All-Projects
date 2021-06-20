/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object {
    public:
        Toy(std::string &name, const std::string &type);
        virtual ~Toy();

        virtual void isTaken() const = 0;

    protected:
        std::string _name;
    private:
};

#endif /* !TOY_HPP_ */
