/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_fill_perfect
*/

#include <criterion/criterion.h>
#include "generator.h"

void fill_perfect(char **map, int width, int heigth);

Test(fill_perfect, map_is_good)
{
    char **map = malloc(sizeof(char *) * (5 + 1));
    for (int i = 0; i < 3; i++) {
        map[i] = malloc(sizeof(char) * 2);
        map[i][0] = '*';
        map[i][1] = 0;
    }
    fill_perfect(map, 1, 1);
    for (int i = 0; i < 3; i++)
        free(map[i]);
    free(map);
}