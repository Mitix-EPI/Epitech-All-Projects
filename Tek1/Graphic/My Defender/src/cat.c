/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "../my_tower.h"

char *cat(char *start, char *line)
{
    int length_start = my_strlen(start);
    int length_line = my_strlen(line);
    char *reslt = NULL;
    int a = 0;

    reslt = malloc(sizeof(char) * (length_start + length_line + 2));
    for (; a < length_start; a += 1)
        reslt[a] = start[a];
    for (int b = 0; b < length_line; b += 1) {
        reslt[a] = line[b];
        a += 1;
    }
    reslt[a] = '\0';
    return (reslt);
}