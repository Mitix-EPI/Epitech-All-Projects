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

void rem_numbers(char *map, square_t *sq_c)
{
    long size = sq_c->size_file;

    my_revstr(map, size);
    for (int i = 0; map[size - sq_c->start + i]; i++) {
        map[size - sq_c->start + i] = 'e';
    }
    my_revstr(map, size);
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