/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** function my_strlen
*/

#include "lemin.h"

int my_strlen(const char *str)
{
    int len = 0;

    for (; str && str[len]; ++len);
    return (len);
}

int count_spaces(char *str)
{
    int len = 0;
    int index = 0;

    if (!str)
        return (0);
    for (; str[index]; ++index)
        if (str[index] == ' ' && str[index + 1] != ' ' && str[index + 1])
            len += 1;
    return (len);
}