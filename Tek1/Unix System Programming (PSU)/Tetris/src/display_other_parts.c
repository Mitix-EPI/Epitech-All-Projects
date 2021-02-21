/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_other_parts
*/

#include "../include/my.h"

void first_part(tetris_t *tetris)
{
    if (my_strcmp(tetris->LEFT, " ") == 0)
        my_printf("Key Left : (space)\n");
    else
        my_printf("Key Left : %s\n", tetris->LEFT);
    if (my_strcmp(tetris->RIGHT, " ") == 0)
        my_printf("Key Right : (space)\n");
    else
        my_printf("Key Right : %s\n", tetris->RIGHT);
    if (my_strcmp(tetris->TURN, " ") == 0)
        my_printf("Key Turn : (space)\n");
    else
        my_printf("Key Turn : %s\n", tetris->TURN);
    if (my_strcmp(tetris->DOWN, " ") == 0)
        my_printf("Key Drop : (space)\n");
    else
        my_printf("Key Drop : %s\n", tetris->DOWN);
}

void second_part(tetris_t *tetris)
{
    if (my_strcmp(tetris->QUIT, " ") == 0)
        my_printf("Key Quit : (space)\n");
    else
        my_printf("Key Quit : %s\n", tetris->QUIT);
    if (my_strcmp(tetris->PAUSE, " ") == 0)
        my_printf("Key Pause : (space)\n", tetris->PAUSE);
    else
        my_printf("Key Pause : %s\n", tetris->PAUSE);
    if (tetris->hide_next == 0)
        my_printf("Next : Yes\n");
    else
        my_printf("Next : No\n");
    my_printf("Level : %d\n", tetris->level);
    my_printf("Size : %d*%d\n", tetris->row, tetris->col);
}