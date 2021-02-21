/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** print
*/

#include "generator.h"

void print_map(char **map, int width, int heigth)
{
    for (int y = 0; y < heigth; y += 1) {
        printf("%s", map[y]);
        if (y < heigth - 1)
            printf("\n");
    }
}