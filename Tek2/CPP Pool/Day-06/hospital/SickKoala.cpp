/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str) : name(str)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string gift)
{
    if (gift.compare("Mars") == 0) {
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } else if (gift.compare("Kinder") == 0) {
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
        return true;
    } else {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return false;
    }
}

void SickKoala::overDrive(std::string sentence)
{
    std::size_t index = 0;
    std::string sub_str = "1337!";

    while ((index = sentence.find("Kreog!")) != std::string::npos) {
        sentence.replace(index, 6, sub_str);
    }
    std::cout << "Mr." << name << ": " << sentence << std::endl;
}

std::string SickKoala::getName(void)
{
    return name;
}
