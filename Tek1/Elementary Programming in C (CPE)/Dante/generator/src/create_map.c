/*
** EPITECH PROJECT, 2020
** generator
** File description:
** create_map
*/

#include "generator.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char **create_map(int y, int x)
{
    char **map = malloc(sizeof(char *) * (y + 1));
    map[y] = NULL;

    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j += 1) {
            if (i % 2 == 0 && j % 2 == 0)
                map[i][j] = 'o';
            else
                map[i][j] = 'X';
        }
        map[i][x] = 0;
    }
    map[y - 1][x - 1] = '*';
    return (map);
}