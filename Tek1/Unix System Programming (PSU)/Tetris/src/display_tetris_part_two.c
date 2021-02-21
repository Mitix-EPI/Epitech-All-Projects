/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_tetris_part_two
*/

#include "../include/my.h"

void display_i(void)
{
    setcolor(2 + 8, 0);
    mvprintw(0, 24, "*");
    mvprintw(1, 24, "*");
    mvprintw(2, 24, "*");
    mvprintw(3, 24, "*");
    mvprintw(4, 24, "*");
    unsetcolor(2 + 8, 0);
}

void display_s(void)
{
    setcolor(1 + 8, 0);
    mvprintw(0, 26, "* * *");
    mvprintw(1, 26, "*    ");
    mvprintw(2, 26, "* * *");
    mvprintw(3, 26, "    *");
    mvprintw(4, 26, "* * *");
    unsetcolor(1 + 8, 0);
}