/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** end
*/

#include "../include/my.h"

int end_program(char **envi, char *str, int r)
{
    free(str);
    for (int i = 0; envi[i] != NULL; i++)
        free(envi[i]);
    free(envi);
    if (r == 0)
        return (0);
    exit(0);
    return (0);
}

int exit_function(char **command, char **envi, char *str)
{
    free(str);
    for (int i = 0; command[i] != NULL; i++)
        free(command[i]);
    free(command);
    for (int i = 0; envi[i] != NULL; i++)
        free(envi[i]);
    free(envi);
    return (0);
}