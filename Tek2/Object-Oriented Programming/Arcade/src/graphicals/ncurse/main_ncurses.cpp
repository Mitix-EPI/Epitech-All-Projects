/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** main_ncurses
*/

#include "ncurses.hpp"

extern "C" {

    IDisplayModule *initDisplay(void)
    {
        IDisplayModule *ncurse = new ncurses;
        return ncurse;
    }
}
