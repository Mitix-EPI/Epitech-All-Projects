/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_parse_string
*/

#include "../include/my.h"

int count_args(char *str, char c)
{
    int i = 0;
    int count = 0;

    for (; str[i]; i++)
        if (str[i] == c)
            count++;
    return (count + 1);
}

int count_nb_char(char *str, char c, int *i)
{
    int count = 0;

    for (; str[*i] != c; *i += 1)
        count += 1;
    *i += 2;
    return (count);
}

int parse_condition(char **tmp, char strx, int a, int j)
{
    if (strx != ' ' && strx != 9)
        tmp[j][a] = strx;
    else
        a--;
    return (a);
}

char **my_parse_string(char *str, char c)
{
    int count_arg = count_args(str, c);
    char **tmp = malloc(sizeof(char *) * (count_arg + 1));
    int x = 0;

    tmp[count_arg] = NULL;
    for (int j = 0, a = 0; j < count_arg; j++, x++) {
        a = 0;
        tmp[j] = malloc(sizeof(tmp[j]) * (1000 + 1));
        for (;str[x] == c || str[x] == 9; x++);
        for (a = 0; str[x] != c && str[x] != 0; x++, a++)
            a = parse_condition(tmp, str[x], a, j);
        tmp[j][a] = 0;
    }
    return (tmp);
}