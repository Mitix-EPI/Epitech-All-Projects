/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "main_santa.hpp"
#include "Toy.hpp"

class Teddy : public Toy {
    public:
        Teddy(std::string name);
        ~Teddy();

        void isTaken(void) const;

    protected:
    private:
};

std::ostream &operator<<(std::ostream &s, const Teddy &teddy);

#endif /* !TEDDY_HPP_ */
