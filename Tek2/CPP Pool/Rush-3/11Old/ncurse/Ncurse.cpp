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
#include "cpu/Cpu.hpp"

#define exitNCurse(status) curs_set(1); endwin(); exit(status);

void displayCore(Cpu *cpu)
{
    int y = 5;
    auto tab = cpu->getPercentage();
    for (const auto &it : cpu->getCPUs()) {
        y += 2;
        mvprintw(y, 0, "%s", it.first.c_str());
        attron(COLOR_PAIR(3));
        for (int i = 0, length = 30; i < length; i++)
            mvprintw(y, i + 10, " ");
        attroff(COLOR_PAIR(3));
        int perc = (round(tab[it.first]) * 30) / 100;
        attron(COLOR_PAIR(1));
        for (int i = 0; i < perc; i++)
            mvprintw(y, i + 10, " ");
        attroff(COLOR_PAIR(1));
        mvprintw(y, 43, "%.0f %%", round(tab[it.first]));
    }
    cpu->clearMap();
}

int main(void)
{
    Cpu cpu;


    initscr(); // Start ncurses
    noecho();
    curs_set(0); // Cursor invisible
    start_color();
    keypad(stdscr, TRUE);
    use_default_colors();

    init_pair(0, COLOR_WHITE, -1);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);

    while (1) {
        // TODO Keymap
        // key = getch();
        // if (key == 27) // ECHAP
        //     exitNCurse(0);
        // if (key == 13) { // ENTER
        //     exitNCurse(0);
        // }
        // TODO Update
        cpu.update();

        // TODO Display
        clear();
        displayCore(&cpu);
        refresh();
        clear();
        sleep(1);
    }
    curs_set(1);
    endwin();
}
