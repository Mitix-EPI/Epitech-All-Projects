/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_print_map
*/

#include "include/my.h"

void print_x_square(char *map, int *map_int, square_t *sq_c)
{
    int x_end = sq_c->x0;
    int x_inter = x_end - ((sq_c->nb_char + 1) * (sq_c->size_square - 1));
    int x_start = x_inter - (sq_c->size_square - 1);
    int size_square = sq_c->size_square;

    for (int i = 0; i < size_square; i++) {
        for (int j = x_start; j <= x_inter; j++)
            map[j] = 'x';
        x_start += (sq_c->nb_char + 1);
        x_inter += (sq_c->nb_char + 1);
    }
}

void print_map(char *map, int size)
{
    int i = 0;

    for (i = 0; map[i] == 'e'; i++);
    for (i; map[i]; i++)
        write(1, &map[i], 1);
}