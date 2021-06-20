/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name) : Toy(WOODY, name, "woody.txt")
{
}

Woody::Woody(const std::string &name, std::string &filename) : Toy(WOODY, name, filename)
{
}

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
}

Woody::~Woody()
{
}
