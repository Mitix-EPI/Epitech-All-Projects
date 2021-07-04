/*
** EPITECH PROJECT, 2021
** B-CNA-410-MPL-4-1-groundhog-alexandre.juan
** File description:
** main bonus
*/

#include "Plazza.hpp"
#include "Graphical.hpp"

bool isNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void displayHelp(void)
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./plazza period" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tmultiplier\tmultiplier for the cooking time of the pizzas" << std::endl;
    std::cout << "\tCooks\tthe number of Cooks per Kitchen" << std::endl;
    std::cout << "\ttime\ttime in milliseconds used by the Kitchen stock to replace ingredients" << std::endl;
}

void displayError(std::string errorMessage)
{
    std::cerr << "Error: " << errorMessage << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        displayHelp();
        return 0;
    }
    if (ac != 4) {
        displayError("Not Enough argument. Please use -h command.");
        return 84;
    }
    if (isNumber(av[1]) && isNumber(av[2]) && isNumber(av[3])) {
        int nb1 = atoi(av[1]);
        int nb2 = atoi(av[2]);
        int nb3 = atoi(av[3]);
        if (nb1 >= 0 && nb2 >= 0 && nb3 >= 0) {
            Plazza plazza(nb1, nb2, nb3);
            plazza.runShell();
            exit(0);
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
