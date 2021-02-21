/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** separation
*/

#include "../include/my.h"

int count_str_right(char *str, int i)
{
    int len = 0;

    i++;
    for (; str[i]; i++, len++);
    return (len);
}

char *right_separation(char *str, int i, char *sym)
{
    int len = count_str_right(str, i);
    char *new = malloc(sizeof(char ) * (len + 1));
    int count = 0;

    new[len] = 0;
    i += my_count(sym);
    for (; count < len; i++, count++)
        new[count] = str[i];
    new[count] = 0;
    return (new);
}

char *left_separation(char *str, int i)
{
    int len = i;
    char *new = malloc(sizeof(char ) * (len + 1));
    int count = 0;

    new[len] = 0;
    for (; count < len; count++)
        new[count] = str[count];
    new[count] = 0;
    return (new);
}