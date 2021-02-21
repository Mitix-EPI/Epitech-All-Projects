/*
** EPITECH PROJECT, 2020
** empty line
** File description:
** return 1 if line is only composed of \t and spaces else 0
*/

#include "asm.h"

int check_empty_line(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return (0);
    return (1);
}