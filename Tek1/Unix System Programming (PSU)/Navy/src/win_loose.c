/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** win_loose.c
*/

#include "../include/my.h"

int condition_loose1(int not_loose, int i, int x, int y)
{
    for (int j = 0; j < data.pos_map[i][0] - 48; y++, j++)
        if (data.board[y][x] != 'x')
            not_loose = 1;
    return (not_loose);
}

int condition_loose2(int not_loose, int i, int x, int y)
{
    for (int j = 0; j < data.pos_map[i][0] - 48; x++) {
        if (data.board[y][x] != ' ') {
            if (data.board[y][x] != 'x') {
                not_loose = 1;
            }
            j++;
        }
    }
    return (not_loose);
}

int check_loose(void)
{
    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 17; j++) {
            if (data.board[i][j] != ' ' && data.board[i][j] != '.' &&
            data.board[i][j] != 'o' && data.board[i][j] != 'x')
                return (0);
        }
    }
    return (1);
}

int win_loose(void)
{
    if (check_loose() == 1) {
        print_board();
        my_putstr("\nEnemy won\n");
        kill(data.pid, SIGUSR1);
        return (1);
    } else {
        kill(data.pid, SIGUSR2);
        return (0);
    }
}

int wait_win_loose(void)
{
    struct sigaction act;

    fill_the_struct_1(&act);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    pause();
    if (data.catch_number == 10) {
        print_board();
        my_putstr("\nI won\n");
        return (1);
    }
    return (0);
}