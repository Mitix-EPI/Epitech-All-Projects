/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_tetris_part_one
*/

#include "../include/my.h"

void display_r(void)
{
    setcolor(3 + 8, 0);
    mvprintw(0, 18, "* * *");
    mvprintw(1, 18, "*   *");
    mvprintw(2, 18, "* *  ");
    mvprintw(3, 18, "*   *");
    mvprintw(4, 18, "*   *");
    unsetcolor(3 + 8, 0);
}

void display_t_2(void)
{
    setcolor(7 + 8, 0);
    mvprintw(0, 12, "* * *");
    mvprintw(1, 12, "  *  ");
    mvprintw(2, 12, "  *  ");
    mvprintw(3, 12, "  *  ");
    mvprintw(4, 12, "  *  ");
    unsetcolor(7 + 8, 0);
}

void display_e(void)
{
    setcolor(5 + 8, 0);
    mvprintw(0, 6, "* * *");
    mvprintw(1, 6, "*    ");
    mvprintw(2, 6, "* *  ");
    mvprintw(3, 6, "*    ");
    mvprintw(4, 6, "* * *");
    unsetcolor(5 + 8, 0);
}

void display_t_1(void)
{
    setcolor(4 + 8, 0);
    mvprintw(0, 0, "* * *");
    mvprintw(1, 0, "  *  ");
    mvprintw(2, 0, "  *  ");
    mvprintw(3, 0, "  *  ");
    mvprintw(4, 0, "  *  ");
    unsetcolor(4 + 8, 0);
}

void display_tetris_name(void)
{
    unsetcolor(6 + 8, 0);
    display_t_1();
    display_e();
    display_t_2();
    display_r();
    display_i();
    display_s();
    setcolor(6 + 8, 0);
}