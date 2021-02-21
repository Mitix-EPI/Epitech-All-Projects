/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** disp_arena
*/

#include "corewar.h"

void open_color(core_t *core, int j)
{
    for (int i = 0; i < core->nb_champs; i++) {
        if (core->champs[i].pc == j) {
            attron(COLOR_PAIR(i + 1));
            return;
        }
    }
    if (core->color_txt[j] == 'B')
        attron(COLOR_PAIR(5));
    if (core->color_txt[j] == 'R')
        attron(COLOR_PAIR(6));
    if (core->color_txt[j] == 'G')
        attron(COLOR_PAIR(7));
    if (core->color_txt[j] == 'Y')
        attron(COLOR_PAIR(8));
}

void close_color(core_t *core, int j)
{
    for (int i = 0; i < core->nb_champs; i++) {
        if (core->champs[i].pc == j) {
            attroff(COLOR_PAIR(i + 1));
            return;
        }
    }
    if (core->color_txt[j] == 'B')
        attroff(COLOR_PAIR(5));
    if (core->color_txt[j] == 'R')
        attroff(COLOR_PAIR(6));
    if (core->color_txt[j] == 'G')
        attroff(COLOR_PAIR(7));
    if (core->color_txt[j] == 'Y')
        attroff(COLOR_PAIR(8));
}

void display_player_info(core_t *core, int cycle)
{
    for (int i = 0; i < core->nb_champs; i++) {
        printw("PLAYER[%d] - name : %s | comment : %s | waiting cycle : %d\n", \
        i + 1, core->champs[i].header.prog_name, core->champs[i].header.comment,
        core->champs[i].wait);
        for (int j = 0; j < 16; j++)
            printw("[%02x] ", core->champs[i].reg[j]);
        printw("\n");
    }
    printw("Cycle : %d / %d\n", cycle, core->ctd);
    printw("\nARENA : \n");
}

void disp_arena(core_t *core, int cycle)
{
    clear();
    noecho();
    display_player_info(core, cycle);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 70 == 0)
            printw("\n");
        open_color(core, i);
        printw("%02hhx", core->arena[i]);
        close_color(core, i);
        printw(" ");
    }
    refresh();
    usleep(70000);
}
