/*
** EPITECH PROJECT, 2020
** cutstr
** File description:
** function to remove all subcontent of a string
*/

#include "lemin.h"

void cutstr(char *str)
{
    int index_space = -1;
    int i = 0;

    for (; str[i]; i += 1) {
        if (str[i] == ' ' && index_space == -1)
            index_space = i;
        if (str[i] == '#' || str[i] == '\n')
            break;
        if (str[i] != ' ' && index_space != -1)
            index_space = -1;
    }
    if (index_space != -1)
        str[index_space] = '\0';
    else
        str[i] = '\0';
}