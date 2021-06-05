/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** main
*/

#include "CoreModule.hpp"
#include "UtilityClasses.hpp"

int displayHelp(void)
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t./arcade library_grah.so" << std::endl << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\tBlabla" << std::endl;
    return 0;
}

void errorDisplay(int errorCode, std::string errorMessage)
{
    std::cerr << "ErrorCode " << errorCode << ": " << errorMessage << std::endl;
    exit(84);
}

int main(int ac, char **av)
{
    if (ac != 2)
        errorDisplay(1, "Number of arguments is invalid");
    if (strcmp(av[1], "-h") == 0)
        return displayHelp();
    CoreModule Core(av[1]);
    Core.launchArcade();
    return 0;
}
