/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** create_empty_map
*/

#include "../include/my.h"

void add_left_board(char **map)
{
    map[0][0] = ' ';
    for (int i = 2, num = '1'; i < 10; i++, num++) {
        map[i][0] = num;
    }
    for (int i = 0; i < 10; i++)
        if (i != 1)
            map[i][1] = '|';
}

void add_top_board(char **map)
{
    for (int i = 0; i < 17; i++) {
        if (i == 1)
            map[1][i] = '+';
        else
            map[1][i] = '-';
    }
    for (int i = 2, alpha = 'A'; i < 17; i++, alpha++) {
        map[0][i] = alpha;
        if (i < 16) {
            i++;
            map[0][i] = ' ';
        }
    }
}

void add_points(char **map)
{
    for (int i = 2; i < 10; i++) {
        for (int x = 2; x < 17; x++) {
            map[i][x] = '.';
            if (x < 16) {
                x++;
                map[i][x] = ' ';
            }
        }
    }
}

char **create_empty_map(void)
{
    char **map = malloc(sizeof(char *) * (10 + 1));
    map[10] = NULL;
    for (int i = 0; i < 10; i++) {
        map[i] = malloc(sizeof(char) * (18 + 1));
        map[i][17] = '\n';
        map[i][18] = 0;
    }
    add_left_board(map);
    add_top_board(map);
    add_points(map);
    return (map);
}