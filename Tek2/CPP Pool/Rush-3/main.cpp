/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-clement.bolin
** File description:
** main
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>
#include <unistd.h>
#include <vector>
#include <map>
#include <math.h>

#include <ncurses.h>
#include <algorithm>
#include "Modules/Cpu.hpp"
#include "Modules/Memory.hpp"
#include "Modules/Time.hpp"
#include "Modules/User.hpp"
#include "Modules/Network.hpp"
#include "Modules/Network.hpp"
// #include "Display/SFML.hpp"
#include "Display/Ncurse.hpp"

void launch_program(bool isNcurse)
{
    if (isNcurse) {
        Ncurse ncurse;
        ncurse.run();
    } else {
        // SFML sfml;
        // sfml.run();
    }
}

int main(int ac, char **av)
{
    if (ac > 2) {
        std::cerr << "USAGE:\n\t./MyGKrellm with -n if ncurse or -s for SFML" << std::endl;
        return (84);
    }
    if (ac == 1 || (av[1][0] == '-' && av[1][1] == 'n'))
        launch_program(true);
    else if ((av[1][0] == '-' && av[1][1] == 's'))
        launch_program(false);
    else {
        std::cerr << "USAGE:\n\t./MyGKrellm with -n if ncurse or -s for SFML" << std::endl;
        return (84);
    }
    return (0);
}