/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** usefull
*/

#include "client/myteams.h"

int check_quote(char *str)
{
    if (str[0] == '\"' && str[strlen(str) - 1] == '\"')
        return (0);
    return (1);
}

char *remove_quote(char *str)
{
    char *new_str = strdup(str);

    if (str[0] == '\"' && str[strlen(str) - 1] == '\"') {
        new_str++;
        new_str[strlen(new_str) - 1] = 0;
    }
    return (new_str);
}