/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string name);
        Woody(std::string name, std::string filename);
        ~Woody();

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
