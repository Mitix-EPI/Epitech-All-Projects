/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print
*/

#include "../include/my.h"

void print_map(matchstick_t *ms)
{
    for (int i = 0; i < (ms->line + 2); i++)
        for (int y = 0; y < (ms->line * 2) + 2; y++)
            write(1, &ms->board[i][y], 1);
}

void print_end_msg(int res)
{
    if (res == 1)
        write(1, "I lost... snif... but I'll get you next line!!\n", 47);
    if (res == 2)
        write(1, "You lost, too bad...\n", 21);
}