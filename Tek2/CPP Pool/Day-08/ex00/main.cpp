/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** main
*/

#include "Droid.hpp"

int main()
{
    Droid d;
    Droid d1("Avenger");
    size_t Durasel = 200;
    std::cout << d << std::endl;
    std::cout << d1 << std::endl;
    d = d1;
    // d.setStatus(new std::string("Kill Kill Kill !"));
    // d << Durasel;
    // std::cout << d << "--" << Durasel << std::endl;
    // Droid d2 = d;
    // d.setId("Rex");
    // std::cout << (d2 != d) << std::endl;
    return 0;
}