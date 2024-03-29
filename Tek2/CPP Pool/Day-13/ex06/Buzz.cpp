/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name) : Toy(BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(const std::string &name, const std::string &filename) : Toy(BUZZ, name, filename)
{
}

bool Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
    return true;
}

Buzz::~Buzz()
{
}
