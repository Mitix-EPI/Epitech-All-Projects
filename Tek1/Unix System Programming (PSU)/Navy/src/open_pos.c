/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** open_pos
*/

#include "../include/my.h"

int count_line(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            count++;
    return (count);
}

int count_charac(char *str, int index)
{
    int count = 0;

    for (int i = index; str[i] != '\n' && str[i] != '\0'; i++, count++);
    return (count);
}

char **open_pos(char *str)
{
    int len = count_line(str) + 1;
    char **map = malloc(sizeof(char *) * (len + 1));
    int x = 0;
    int x1 = 0;

    map[len] = NULL;
    for (int i = 0; i < len; i++) {
        x1 = 0;
        map[i] = malloc(sizeof(char) * (count_charac(str, x) + 1));
        for (; str[x] != '\0' && str[x] != '\n'; x++, x1++) {
            map[i][x1] = str[x];
        }
        map[i][x1] = 0;
        x++;
    }
    return (map);
}