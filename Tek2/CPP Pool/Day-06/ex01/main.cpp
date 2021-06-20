/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** main
*/

#include "convert.hpp"

int main(void)
{
    std::string line;
    std::stringstream buffer;
    float nb;
    std::string type;
    std::getline(std::cin, line);
    buffer << line;
    buffer >> nb;
    buffer >> type;
    int typeInt = type.find("Celsius") ? 0 : 1;
    float res = convert(nb, typeInt);
    std::string typeRes = typeInt ? "Fahrenheit" : "Celsius";
    std::cout << std::setw(16) << std::fixed << std::setprecision(3)
    << res << std::setw(16) << typeRes << std::endl;
    return 0;
}
