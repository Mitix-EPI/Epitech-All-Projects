/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** create_map
*/

#include "../include/my.h"

void set_start_end(char **board, int line)
{
    for (int i = 0, x = 0; board[i][x] != '\n'; x++)
        board[i][x] = '*';

    for (int i = line + 1, x = 0; board[i][x] != '\n'; x++)
        board[i][x] = '*';

    for (int i = 1; i < line + 1; i++)
        board[i][0] = '*';

}

void set_matches(char **board, int line)
{
    int nb_space = 0;
    int nb_matches = (line * 2) - 1;

    for (int y = line; y > 0; y--, nb_space++, nb_matches -= 2) {
        for (int x = 1; x < (line * 2); x++) {
            for (int i = 0; i < nb_space; i++, x++)
                board[y][x] = ' ';
            for (int i = 0; i < nb_matches; i++, x++)
                board[y][x] = '|';
            for (int i = 0; i < nb_space; i++, x++)
                board[y][x] = ' ';
        }
    }
}

char **print_my_lucas(int line)
{
    char **board = malloc(sizeof(char *) * ((line + 2) + 1));

    board[line + 2] = NULL;
    for (int i = 0; i < line + 2; i++) {
        board[i] = malloc(sizeof(char) * (((line * 2) + 2) + 1));
        for (int y = 0; y < line * 2 + 2; y++)
            board[i][y] = ' ';
        board[i][line * 2] = '*';
        board[i][(line * 2) + 1] = '\n';
        board[i][(line * 2) + 2] = 0;
    }
    set_start_end(board, line);
    set_matches(board, line);
    return (board);
}