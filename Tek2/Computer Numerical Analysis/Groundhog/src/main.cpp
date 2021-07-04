/*
** EPITECH PROJECT, 2021
** B-CNA-410-MPL-4-1-groundhog-alexandre.juan
** File description:
** main
*/

#include "../include/groundhog.hpp"

bool isNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void displayHelp(void)
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./groundhog period" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tperiod\tthe number of days defining a pediod" << std::endl;
}

void displayError(std::string errorMessage)
{
    std::cerr << "Error: " << errorMessage << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        displayError("Not Enough argument. Please use -h command.");
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        displayHelp();
        return 0;
    }
    if (isNumber(av[1])) {
        int nb = atoi(av[1]);
        if (nb >= 0) {
            std::size_t period = nb;
            shellGroundhog(period);
        } else {
            displayError("Not good Argument. Please use -h command.");
            return 84;
        }
    } else {
        displayError("Not good Argument. Please use -h command.");
        return 84;
    }
    return 0;
}
