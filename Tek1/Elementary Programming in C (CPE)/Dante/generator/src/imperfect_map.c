/*
** EPITECH PROJECT, 2020
** generator
** File description:
** imperfect_map
*/

#include "generator.h"

char **imperfect_generate(char **map, int w, int h)
{
    int count = (h * w) / 2;
    int y = 0;
    int x = 0;

    for (int i = 0; i < count; i++) {
        y = rand() % h;
        x = rand() % w;
        if (map[y][x] == 'X')
            map[y][x] = '*';
    }
    return (map);
}