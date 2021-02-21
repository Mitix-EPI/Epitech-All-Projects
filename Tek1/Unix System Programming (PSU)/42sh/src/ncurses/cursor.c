/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** cursor
*/

#include <ncurses/ncurses.h>

void cursor_home(int *i)
{
    printf("\0338");
    *i = 0;
}

void cursor_end(int *i, char *input)
{
    for (int j = my_strlen(input), k = *i; k < j; k++) {
        printf("\033[C");
    }
    *i = my_strlen(input);
}
