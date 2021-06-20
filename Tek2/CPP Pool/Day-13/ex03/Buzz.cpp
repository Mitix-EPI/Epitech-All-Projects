/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name) : Toy(BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(std::string name, std::string filename) : Toy(BUZZ, name, filename)
{
}

void Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
}

Buzz::~Buzz()
{
}
