/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_getch1
*/

#include "../include/my.h"

int mygetch(void)
{
    int ch = 0;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return (ch);
}