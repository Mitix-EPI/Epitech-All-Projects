/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game_loop_player2
*/

#include "../include/my.h"

char *build_coord(char letter, char nb)
{
    char *str = malloc(sizeof(char) * (2 + 1));

    str[0] = letter;
    str[1] = nb;
    str[2] = 0;
    return (str);
}

void game_loop_player2(void)
{
    char *str = NULL;
    int i2 = 0;

    for (int i = 0; 1; str = NULL, i = 0, i2 = 0) {
        str = NULL;
        print_board();
        my_putstr("\nwaiting for enemy's attack...");
        str = translater();
        send_hit_or_missed(str);
        i = check_touch(str);
        update_board(data.board, str, i);
        str = check_input();
        str_to_signal(str);
        i = receive_hit_missed(str);
        update_board(data.enn_board, str, i);
        i = win_loose();
        i2 = wait_win_loose();
        if (i == 1 || i2 == 1)
            break;
    }
}