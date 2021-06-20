/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** Parts
*/

#include "Parts.hpp"

// Arms
Arms::Arms(std::string const &serial, bool functional) : _serial(serial), _functional(functional)
{
}

Arms::~Arms()
{
}

bool Arms::isFunctional(void) const
{
    return _functional;
}

std::string Arms::serial(void) const
{
    return _serial;
}

void Arms::informations(void) const
{
    std::string res = isFunctional() ? "OK" : "KO";
    std::cout << "[Parts] " << "Arms " << _serial << " status : " << res << std::endl;
}

// Legs
Legs::Legs(std::string const &serial, bool functional) : _serial(serial), _functional(functional)
{
}

Legs::~Legs()
{
}

bool Legs::isFunctional(void) const
{
    return _functional;
}

std::string Legs::serial(void) const
{
    return _serial;
}

void Legs::informations(void) const
{
    std::string res = isFunctional() ? "OK" : "KO";
    std::cout << "[Parts] " << "Legs " << _serial << " status : " << res << std::endl;
}

// Head
Head::Head(std::string const &serial, bool functional) : _serial(serial), _functional(functional)
{
}

Head::~Head()
{
}

bool Head::isFunctional(void) const
{
    return _functional;
}

std::string Head::serial(void) const
{
    return _serial;
}

void Head::informations(void) const
{
    std::string res = isFunctional() ? "OK" : "KO";
    std::cout << "[Parts] " << "Head " << _serial << " status : " << res << std::endl;
}
