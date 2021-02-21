/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_win_loose_conditions
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int condition_loose2(int not_loose, int i, int x, int y);

int condition_loose1(int not_loose, int i, int x, int y);

Test(condition_loose2, return_0_or_1)
{
    data.pos_map = create_fill_map("pos1");
    data.board = create_empty_map();
    cr_assert_eq(condition_loose2(0, 0, 6, 7), 0);
    cr_assert_eq(condition_loose2(1, 0, 6, 7), 1);
    cr_assert_eq(condition_loose2(0, 4, 6, 8), 1);
    for (int i = 0; data.pos_map[i] != NULL; i++)
        free(data.pos_map[i]);
    free(data.pos_map);
    for (int i = 0; data.board[i] != NULL; i++)
        free(data.board[i]);
    free(data.board);
}

Test(condition_loose1, return_0_or_1)
{
    data.pos_map = create_fill_map("pos1");
    data.board = create_empty_map();
    cr_assert_eq(condition_loose1(0, 0, 6, 7), 0);
    cr_assert_eq(condition_loose1(0, 4, 6, 6), 1);
    for (int i = 0; data.pos_map[i] != NULL; i++)
        free(data.pos_map[i]);
    free(data.pos_map);
    for (int i = 0; data.board[i] != NULL; i++)
        free(data.board[i]);
    free(data.board);
}