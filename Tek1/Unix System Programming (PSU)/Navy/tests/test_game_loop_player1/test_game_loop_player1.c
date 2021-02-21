/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_game_loop_player1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(print_board, print_things)
{
    data.board = malloc(sizeof(char *) * (1 + 1));
    data.board[0] = " ";
    data.board[1] = NULL;
    data.enn_board = malloc(sizeof(char *) * (1 + 1));
    data.enn_board[0] = " ";
    data.enn_board[1] = NULL;
    cr_redirect_stdout();
    print_board();
    cr_assert_stdout_eq_str("\nmy positions:\n \nenemy's positions:\n ");
    free(data.board);
    free(data.enn_board);
}

Test(str_to_signal, return_nothing)
{
    char *txt = malloc(sizeof(char) * 3);
    data.pid = 10000;
    txt[0] = 'A';
    txt[1] = '1';
    txt[2] = 0;
    str_to_signal(txt);
    free(txt);
}