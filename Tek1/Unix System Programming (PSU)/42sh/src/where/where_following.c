/*
** EPITECH PROJECT, 2020
** where_following.c
** File description:
** where_following.c
*/

#include "where/where_following.h"

int check_valid_command(char **command)
{
    int error = 0;
    int x = 0;

    for (int i = 0; command[i]; i++) {
        x = 0;
        for (int j = 0; command[i][j]; j++) {
            (command[i][j] == '/') ? error = 1 : 0;
            (command[i][j] == '/') ? x = 1 : 0;
        }
        (x == 1) ? printf("where: / in command makes no sense\n") : 0;
    }
    if (error == 1) {
        return (1);
    }
    return (0);
}