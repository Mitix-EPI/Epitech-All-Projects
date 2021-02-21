/*
** EPITECH PROJECT, 2020
** my isnum
** File description:
** return 1 if a string contain only digits
*/

#include "asm.h"

int my_isnum(char const *str)
{
    for (int i = 0; str && str[i]; i += 1)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}