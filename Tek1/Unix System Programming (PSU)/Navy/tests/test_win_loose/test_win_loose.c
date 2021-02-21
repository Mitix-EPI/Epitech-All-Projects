/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_win_loose
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(win_loose, return_1)
{
    data.board = create_empty_map();
    data.enn_board = create_empty_map();
    data.pid = 10000;
    cr_assert_eq(win_loose(), 1);
    for (int i = 0; data.board[i] != NULL; i++)
        free(data.board[i]);
    free(data.board);
}

Test(win_loose, return_0)
{
    data.board = create_empty_map();
    data.pid = 10000;
    data.board[4][6] = 'A';
    cr_assert_eq(win_loose(), 0);
    for (int i = 0; data.board[i] != NULL; i++)
        free(data.board[i]);
    free(data.board);
}