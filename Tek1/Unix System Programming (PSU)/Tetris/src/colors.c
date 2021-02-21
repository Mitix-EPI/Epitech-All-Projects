/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** colors
*/

#include "../include/my.h"

int is_bold(int fg)
{
    int i = 0;

    i = 1 << 3;
    return (i & fg);
}

void setcolor(int fg, int bg)
{
    attron(COLOR_PAIR(colornum(fg, bg)));
    if (is_bold(fg))
        attron(A_BOLD);
}

void unsetcolor(int fg, int bg)
{
    attroff(COLOR_PAIR(colornum(fg, bg)));
    if (is_bold(fg))
        attroff(A_BOLD);
}