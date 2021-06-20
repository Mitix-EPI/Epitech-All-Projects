/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** pyramid
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int pyramid_path(int size, int **map)
{
    int **calc_map = malloc(sizeof(int *) * (size));
    for (int i = 0; i < size; i++) {
        calc_map[i] = malloc(sizeof(int) * (i + 1));
        for (int j = 0; j < i + 1; j++)
            calc_map[i][j] = map[i][j];
    }

    for (int i = size - 2; i >= 0; i -= 1)
        for (int j = 0; j < i + 1; j++)
            calc_map[i][j] += min(calc_map[i + 1][j], calc_map[i + 1][j + 1]);
    return calc_map[0][0];
}
