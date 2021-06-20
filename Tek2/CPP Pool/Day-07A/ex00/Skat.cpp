/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPacks) : _name(name), _stimPaks(stimPacks)
{
}

Skat::~Skat()
{
}

const std::string &Skat::name(void)
{
    return _name;
}

int &Skat::stimPaks(void)
{
    return _stimPaks;
}

int Skat::stimPaks(int new_stimPacks)
{
    _stimPaks = new_stimPacks;
    return _stimPaks;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_stimPaks - number >= 0) {
        std::cout << "Keep the change." << std::endl;
        _stimPaks -= number;
        stock += number;
    } else {
        std::cout << "Don't be greedy" << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _stimPaks += number;
}

void Skat::useStimPaks(void)
{
    if (_stimPaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        _stimPaks -= 1;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status(void)
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
