/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** remove_dot_tetrimino
*/

#include "../include/my.h"

char *remove_dot_tetrimino(char *str)
{
    int len = my_strlen(str) - my_strlen(".tetrimino");
    char *new = malloc(sizeof(char) * (len + 1));
    new[len] = '\0';
    for (int i = 0; i != len; i += 1)
        new[i] = str[i];
    return (new);
}