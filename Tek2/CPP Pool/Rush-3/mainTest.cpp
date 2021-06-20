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

#define exitNCurse(status) curs_set(1); endwin(); exit(status);

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void displayCore(Cpu *cpu, Memory *mem)
{
    attron(COLOR_PAIR(2));
    rectangle(5, 0, 19, 58);
    attroff(COLOR_PAIR(2));
    // CPUs
    int y = 5;
    auto tab = cpu->getPercentage();
    std::string all_cpu;
    auto all = cpu->getCPUs();
    for (size_t length = 0; length < tab.size(); length += 1) {
        all_cpu = "cpu" + std::to_string(length);
        y += 2;
        mvprintw(y, 2, "%s", all_cpu.c_str());
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
    mvprintw(y, 2, "Memory");
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
    mvprintw(y, 2, "Swap");
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
    attron(COLOR_PAIR(0));
    rectangle(0, 0, 4, 58);
    mvprintw(1, 2, "Username: %s", user->getUserName().c_str());
    int x = 2;
    size_t count = 0;
    mvprintw(2, x, "Host:    ");
    x += 10;
    for (const auto &it : user->getHostName()) {
        mvprintw(2, x, "%s", it.c_str());
        x += it.length();
        count += 1;
        if (user->getHostName().size() > count) {
            x += 2;
            mvprintw(2, x, ", ");
        }
    }
    mvprintw(3, 2, "Version:  %s", user->getOsVersion().c_str());
    attroff(COLOR_PAIR(0));
    attron(COLOR_PAIR(6));
    rectangle(0, 59, 4, 100);
    attroff(COLOR_PAIR(6));
    std::string date = time->getActualDate();
    std::replace(date.begin(), date.end(), ':', '/');
    mvprintw(1, 61, "Date: %s", date.c_str());
    mvprintw(2, 61, "Hour: %s", time->getActualTime().c_str());
    mvprintw(3, 61, "Uptime: %s", time->getUptime().c_str());
}

void displayDataTransfer(Network *network)
{
    attron(COLOR_PAIR(7));
    rectangle(5, 59, 23, 100);
    attroff(COLOR_PAIR(7));
    mvprintw(6, 60, "Network Data Transfer:");
    int y = 8;
    std::vector<network_data_t> data = network->getData();
    for (int i = 0; i < network->getSize(); i++) {
        mvprintw(y, 60, "%s:", data[i].name.c_str());
        mvprintw(y + 1, 65, "UP => %.2fKb/s", data[i].up);
        mvprintw(y + 2, 65, "DOWN => %.2fKb/s", data[i].down);
        y += 3;
    }
}

int main(void)
{
    Cpu cpu;
    Memory mem;
    User user;
    Time time;
    Network network;


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
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, -1);
    init_pair(7, COLOR_BLUE, -1);

    while (1) {
        // TODO Keymap
        // HERE

        // TODO Update
        cpu.updateData();
        time.updateData();
        user.updateData();
        network.updateData();

        // TODO Display
        clear();
        displayCore(&cpu, &mem);
        displayUserInfo(&user, &time);
        displayDataTransfer(&network);
        refresh();
        clear();
        sleep(1);
    }
    curs_set(1);
    endwin();
}
