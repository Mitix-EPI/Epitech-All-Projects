/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** disp_arena
*/

#include "corewar.h"

// char *calc_base(int nb, char *base)
// {
//     int i = 0;
//     int k = 0;
//     char *result = malloc(sizeof(result));

//     result = (nb == 0) ? my_strcat("0", "\0") : result;
//     while (nb > 0) {
//         i = nb % my_strlen(base);
//         result[k] = base[i];
//         k += 1;
//         nb /= my_strlen(base);
//     }
//     my_revstr(result);
//     result = (my_strlen(result) == 1) ? my_strcat("0", result) : result;
//     return (result);
// }

// void print_arena(char *arena)
// {
//     char *tmp = NULL;

//     my_putstr(1, "ARENA\n");
//     for (int i = 0; i < MEM_SIZE; i++) {
//         if (i % 64 == 0)
//             my_putstr(1, "\n");
//         tmp = calc_base(arena[i], "0123456789ABCDEF");
//         my_putstr(1, tmp);
//         my_putstr(1, " ");
//         // free(tmp);
//     }
//     my_putstr(1, "\n\n\n");
// }

// void disp_arena(core_t *core, int cycle)
// {
//     static int my_cycle = 0;

//     if (core->dump == 1 && my_cycle == core->dump_nbr) {
//         for (int i = 0; i < 16; i++)
//             printf("[%d] ", core->champs[0].reg[i]);
//         printf("\n\n");
//         // print_arena(core->arena);
//         my_cycle = 0;
//     } else {
//         my_cycle += 1;
//     }
// }

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
        core->champs[i].to_wait.ctw);
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
    printw("y'a un blem nan ?\n");
    refresh();
    usleep(70000);
}