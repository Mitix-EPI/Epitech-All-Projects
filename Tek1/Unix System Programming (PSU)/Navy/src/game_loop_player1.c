/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** game_loop_player1.c
*/

#include "../include/my.h"

void print_board(void)
{
    my_putstr("\nmy positions:\n");
    for (int i = 0; data.board[i] != 0; i += 1)
        my_putstr(data.board[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; data.enn_board[i] != 0; i += 1)
        my_putstr(data.enn_board[i]);
}

char *check_input(void)
{
    char *file = malloc(sizeof(char) * (1024 + 1));
    int rd = -1;

    file[1024] = 0;
    while (1) {
        my_putstr("\nattack: ");
        rd = read(0, file, sizeof(file));
        file[rd] = 0;
        if (rd < 2 || (my_str_isalpha(file) == 1 || my_strlen(file) != 2)) {
            my_putstr("wrong position");
        } else {
            if (file[1] >= 49 && file[1] <= 56)
                break;
            my_putstr("wrong position");
        }
        for (int i = 0; i < 1024; i++)
            file[i] = 0;
    }
    return (file);
}

void game_loop_player1(void)
{
    char *str = NULL;
    int i = 0;
    int i2 = 0;

    for (; 1; str = NULL, i = 0, i2 = 0) {
        print_board();
        str = check_input();
        str_to_signal(str);
        i = receive_hit_missed(str);
        update_board(data.enn_board, str, i);
        my_putstr("\nwaiting for enemy's attack...");
        str = translater();
        send_hit_or_missed(str);
        i = check_touch(str);
        update_board(data.board, str, i);
        i = wait_win_loose();
        i2 = win_loose();
        if (i == 1 || i2 == 1)
            break;
    }
}

void str_to_signal(char *str)
{
    int i = str[0] + 1 - 'A';
    for (int j = 0; j < i; j++) {
        kill(data.pid, SIGUSR1);
        usleep(1000);
    }
    kill(data.pid, SIGUSR2);
    usleep(1000);
    i = str[1] - '0';
    for (int j = 0; j < i; j++) {
        kill(data.pid, SIGUSR1);
        usleep(1000);
    }
    kill(data.pid, SIGUSR2);
}