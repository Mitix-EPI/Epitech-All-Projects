/*
** EPITECH PROJECT, 2020
** generator
** File description:
** create_algo
*/

#include "generator.h"

int if_condition(char **map, int i, int j)
{
    if (i == 0) {
        map[i][j] = '*';
        return (0);
    }
    if (j % 2 == 0 && i % 2 == 0) {
        map[i][j] = '*';
        return (0);
    }
    if (j % 2 != 0 && i % 2 == 0) {
        map[i][j] = 'X';
        return (0);
    }
    if (i % 2 != 0) {
        map[i][j] = 'X';
        return (0);
    }
    if (j % 2 != 0)
        map[i][j] = 'X';
    return (0);
}

char **create_map2(int y, int x)
{
    char **map = malloc(sizeof(char *) * (y + 1));
    map[y] = NULL;

    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j += 1) {
            if_condition(map, i, j);
        }
        map[i][x] = 0;
    }
    map[y - 1][x - 1] = '*';
    return (map);
}

void create_perfect(int width, int heigth)
{
    char **map = create_map(heigth, width);

    srand(time(NULL));
    if (width * heigth < 1000000)
        fill_perfect(map, 0, 0);
    else {
        for (int i = 0; map[i]; i += 1)
            free(map[i]);
        free(map);
        map = create_map2(heigth, width);
        fill_perfect_ite(map, width, heigth);
    }
    if (map[heigth - 1][width - 2] == 'X' && map[heigth - 2][width - 1] == 'X')
        map[heigth - 1][heigth - 2] = '*';
    print_map(map, width, heigth);
}

void create_imperfect(int width, int heigth)
{
    char **map = create_map(heigth, width);

    srand(time(NULL));
    if (width * heigth < 1000000)
        fill_perfect(map, 0, 0);
    else {
        for (int i = 0; map[i]; i += 1)
            free(map[i]);
        free(map);
        map = create_map2(heigth, width);
        fill_perfect_ite(map, width, heigth);
    }
    imperfect_generate(map, width, heigth);
    if (map[heigth - 1][width - 2] == 'X' && map[heigth - 2][width - 1] == 'X')
        map[heigth - 1][heigth - 2] = '*';
    print_map(map, width, heigth);
}