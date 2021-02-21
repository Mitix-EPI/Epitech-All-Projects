/*
** EPITECH PROJECT, 2020
** my checking what line
** File description:
** Checking if line of lemin is a node or a link
*/

#include "lemin.h"

int count_numbers(char *line, int type)
{
    int nb_spaces = 0;
    int nb_tirets = 0;

    for (int i = 0; line[i]; i += 1) {
        if (line[i] == ' ')
            nb_spaces += 1;
        if (line[i] == '-')
            nb_tirets += 1;
        if (line[i] == '#')
            break;
    }
    if (type == 0)
        return (nb_spaces);
    else
        return (nb_tirets);
}

int what_line(char *line)
{
    int ret = 0;
    int count = 0;

    for (int i = 0; line[i]; i += 1) {
        if (line[i] == '#')
            break;
        if (line[i] == '-')
            ret = 1;
    }
    count = count_numbers(line, ret);
    if (ret == 0 && count != 2)
        ret = -1;
    if (ret == 1 && count != 1)
        ret = -1;
    return (ret);
}