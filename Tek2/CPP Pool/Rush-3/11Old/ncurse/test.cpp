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
#include "../cpu/Cpu.hpp"
#include "../Core_Monitor/Memory.hpp"
#include "../Core_Monitor/Time.hpp"
#include "../Core_Monitor/Name.hpp"

#define exitNCurse(status) curs_set(1); endwin(); exit(status);

void displayCore(Cpu *cpu, Memory *mem)
{
    // CPUs
    int y = 5;
    auto tab = cpu->getPercentage();
    std::string all_cpu;
    auto all = cpu->getCPUs();
    for (size_t length = 0; length < tab.size(); length += 1) {
        all_cpu = "cpu" + std::to_string(length);
        y += 2;
        mvprintw(y, 1, "%s", all_cpu.c_str());
        attron(COLOR_PAIR(3));
        for (int i = 1, length = 30; i < length; i++)
            mvprintw(y, i + 9, " ");
        attroff(COLOR_PAIR(3));
        int perc = (round(tab[all_cpu.c_str()]) * 30) / 100;
        attron(COLOR_PAIR(1));
        for (int i = 1; i < perc; i++)
            mvprintw(y, i + 9, " ");
        attroff(COLOR_PAIR(1));
        mvprintw(y, 43, "%.0f %%", round(tab[all_cpu.c_str()]));
    }
    cpu->clearMap();

    // Mem
    int length = 30;
    y += 2;
    mvprintw(y, 1, "Memory");
    attron(COLOR_PAIR(3));
    for (int i = 1; i < length; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    int cachedMemoryPercentage = round((mem->getCurrentRamMB() * 30) / mem->getTotalRamMB());
    for (int i = 1; i < cachedMemoryPercentage; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(4));
    mvprintw(y, 43, "%.2fG/%.2fG", mem->getCurrentRamMB(), mem->getTotalRamMB());

    // Swap
    y += 2;
    mvprintw(y, 1, "Swap");
    attron(COLOR_PAIR(3));
    for (int i = 1, length = 30; i < length; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(5));
    int swapPercentage = round(((mem->getFreeSwapMB() * 0.000000954) * 30) / mem->getTotalSwapMB());
    if (swapPercentage < 2)
        swapPercentage = 2;
    for (int i = 1; i < swapPercentage; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(5));
    mvprintw(y, 43, "%.1fM/%.2fG", mem->getFreeSwapMB(), mem->getTotalSwapMB());
}

void displayUserInfo(Name *user, Time *time)
{
}

int main(void)
{
    Cpu cpu;
    Memory mem;
    Name user;
    Time time;
    MEVENT event;


    initscr(); // Start ncurses
    noecho();
    curs_set(0); // Cursor invisible
    start_color();
    keypad(stdscr, TRUE);
    use_default_colors();
    timeout(1);

    init_pair(0, COLOR_WHITE, -1);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    int key = 0;
    while (1) {
        // TODO Keymap
        // } else if (key == ERR)
        //     continue;
        // if (key == 27) // ECHAP
        //     exitNCurse(0);
        // if (key == 13) { // ENTER
        //     exitNCurse(0);
        // }
        // TODO Update
        cpu.update();

        // TODO Display
        clear();
        // displayCore(&cpu, &mem);
        // key = getch();
        // mvprintw(20, 20, "getch : %d", key);
        // if (key == KEY_MOUSE) {
        //     mvprintw(2, 30, "KOOI");
        //     if(getmouse(&event) == OK) {
        //         mvprintw(2, 2, "x:%d / y:%d", event.x, event.y);
        //     }
        // }
        // displayUserInfo(&user, &time);
        refresh();
        clear();
        sleep(1);
    }
    curs_set(1);
    endwin();
}
