/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq_find_biggest_square
*/

#include "include/my.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static change_to_int_t func[] =
{
    {'.', 1},
    {'o', 0},
    {'\n', -3}
};

void coord_biggest_square(char *map, int *map_int, square_t *sq_c)
{
    int start = sq_c->start;

    sq_c->nb_line_square = 0;
    sq_c->size_square = 0;
    for (int i = 0; i < sq_c->size_file - start; i++) {
        if (map_int[i] == -3)
            sq_c->nb_line_square++;
        if (map_int[i] > sq_c->size_square) {
            sq_c->size_square = map_int[i];
            sq_c->x0 = i + start;
        }
    }
    if (sq_c->nb_line_square != sq_c->nb_lines) {
        free(map);
        free(map_int);
        exit(84);
    }
}

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

void rem_numbers(char *map, square_t *sq_c)
{
    long size = sq_c->size_file;
    my_revstr(map, size);
    for (int i = 0; map[size - sq_c->start + i]; i++) {
        map[size - sq_c->start + i] = 'e';
    }
    my_revstr(map, size);
}

void print_map(char *map, int size)
{
    int i = 0;
    int color = 1;


    for (i = 0; map[i] == 'e'; i++);
    for (i; map[i]; i++) {
        if (color > 7)
            color = 1;
        if (map[i] != 'x')
            write(1, &map[i], 1);
        else {
            my_print_color(map[i], color);
            write(1, &map[i], 1);
            my_putstr("\033[0m");
            color++;
        }
    }
}

void bsq_find_biggest_square(char *map, long size)
{
    square_t sq_c;
    int start = 0;
    int *map_int = malloc(sizeof(map_int) * (size - start));

    sq_c.start = calc_start(map);
    start = sq_c.start;
    sq_c.nb_lines = my_getnbr(map);
    sq_c.nb_char = my_linelen(map);
    sq_c.size_file = size;
    for (int i = 0; map[start]; start++, i++)
        for (int a = 0; a < 3; a++)
            if (map[start] == func[a].c)
                map_int[i] = func[a].nb;
    calc_int(map_int, &sq_c);
    coord_biggest_square(map, map_int, &sq_c);
    print_x_square(map, map_int, &sq_c);
    rem_numbers(map, &sq_c);
    print_map(map, size);
    free(map_int);
}