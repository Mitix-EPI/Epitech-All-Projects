/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** update_map
*/

#include "../include/my.h"

void update_board(char **board, char *coord, int i)
{
    char missile = ' ';
    int x = 0;
    int y = 0;

    if (i == 1) {
        missile = 'x';
    } else
        missile = 'o';
    for (; board[0][x] && board[0][x] != coord[0]; x++);
    for (; board[y][0] && board[y][0] != coord[1]; y++);
    if (board[y][x] == 'x') {
        missile = 'x';
    }
    board[y][x] = missile;
}