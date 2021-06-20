/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name) : Toy(WOODY, name, "woody.txt")
{
}

Woody::Woody(std::string name, std::string filename) : Toy(WOODY, name, filename)
{
}

Woody::~Woody()
{
}
