/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** display a string
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i = i + 1;
    return (i);
}

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}