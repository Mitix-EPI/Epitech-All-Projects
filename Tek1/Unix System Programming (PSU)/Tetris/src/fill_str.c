/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** fill_str
*/

#include "../include/my.h"

char *fill_str(char *str, char c, int size)
{
    for (int i = 0; i <= size; i++)
        str[i] = c;
    return (str);
}