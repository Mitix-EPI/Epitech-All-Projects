/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main_generator
*/

#include "generator.h"

void check_up_left_ite(char **map, int i, int j, vector_t *up_rigth)
{
    if (i - 1 > 0 && map[i - 1][j] == 'X')
        up_rigth->y = 1;
    if (j - 1 > 0 && map[i][j - 1] == 'X')
        up_rigth->x = 1;
}

void destroy_walls_ite(vector_t up_left, char **map, int i, int j)
{
    if (up_left.x == 1 && up_left.y == 0)
        map[i][j - 1] = '*';
    if (up_left.x == 0 && up_left.y == 1)
        map[i - 1][j] = '*';
    if (up_left.x == 1 && up_left.y == 1) {
        if (rand() % 2 == 0)
            map[i][j - 1] = '*';
        else
            map[i - 1][j] = '*';
    }
}

void fill_perfect_ite(char **map, int width, int heigth)
{
    vector_t up_left = {0, 0};

    for (int i = 0; i < heigth; i += 2) {
        up_left.x = 0;
        up_left.y = 0;
        for (int j = 0; j < width; j += 2) {
            check_up_left_ite(map, i, j, &up_left);
            destroy_walls_ite(up_left, map, i, j);
        }
    }
}