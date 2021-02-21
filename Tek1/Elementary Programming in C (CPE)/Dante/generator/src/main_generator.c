/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main_generator
*/

#include "generator.h"

char *get_neigth(char **map, int i, int j)
{
    int len = 0;
    char *neig = malloc(sizeof(char) * 6);
    int idx = 0;

    neig[5] = 0;
    for (int k = 0; k < 5; k += 1)
        neig[k] = 'N';
    for (; map[len]; len += 1);
    if (j - 2 > 0 && map[i][j - 2] == 'o')
        neig[idx++] = 'G';
    if (j + 2 < my_strlen(map[0]) && map[i][j + 2] == 'o')
        neig[idx++] = 'D';
    if (i - 2 > 0 && map[i - 2][j] == 'o')
        neig[idx++] = 'H';
    if (i + 2 < len && map[i + 2][j] == 'o')
        neig[idx++] = 'B';
    return (neig);
}

void destroy_wall(char **map, int *vector, int i, int j)
{
    map[i + vector[1]][j + vector[0]] = '*';
    return (fill_perfect(map, i + (2 * vector[1]), j + (2 * vector[0])));
}

void choose_wall(char **map, int i, int j, char c)
{
    if (c == 'G')
        return (destroy_wall(map, (int []) {-1, 0}, i, j));
    if (c == 'D')
        return (destroy_wall(map, (int []) {1, 0}, i, j));
    if (c == 'H')
        return (destroy_wall(map, (int []) {0, -1}, i, j));
    if (c == 'B')
        return (destroy_wall(map, (int []) {0, 1}, i, j));
}

void fill_perfect(char **map, int i, int j)
{
    char *nei = get_neigth(map, i, j);
    int nb = 0;
    int idx = rand();

    map[i][j] = '*';
    for (; nei[nb] != 'N'; nb += 1);
    if (nb == 0)
        return;
    if (nb == 1)
        return (choose_wall(map, i, j, nei[idx % nb]));
    idx = idx % nb;
    if (nei[idx] == 'G')
        destroy_wall(map, (int []) {-1, 0}, i, j);
    if (nei[idx] == 'D')
        destroy_wall(map, (int []) {1, 0}, i, j);
    if (nei[idx] == 'H')
        destroy_wall(map, (int []) {0, -1}, i, j);
    if (nei[idx] == 'B')
        destroy_wall(map, (int []) {0, 1}, i, j);
    free(nei);
    return (fill_perfect(map, i, j));
}