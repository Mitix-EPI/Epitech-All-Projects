/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(std::string name);
        Buzz(std::string name, std::string filemane);
        ~Buzz();

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
