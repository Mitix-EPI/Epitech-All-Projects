/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "../my_tower.h"

int my_strlen(char *str)
{
    int length = 0;

    if (str == NULL)
        return (0);
    while (str[length] != '\0') {
        length += 1;
    }
    return (length);
}