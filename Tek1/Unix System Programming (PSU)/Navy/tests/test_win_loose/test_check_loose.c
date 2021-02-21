/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_check_loose.c
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int check_loose(void);

Test(check_loose, return_1)
{
    data.board = create_empty_map();
    cr_assert_eq(check_loose(), 1);
    for (int i = 0; data.board[i] != NULL; i++)
        free(data.board[i]);
    free(data.board);
}

Test(check_loose, return_0)
{
    data.board = create_empty_map();
    data.board[4][6] = 'A';
    cr_assert_eq(check_loose(), 0);
    for (int i = 0; data.board[i] != NULL; i++)
        free(data.board[i]);
    free(data.board);
}