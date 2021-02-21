/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_check_if_last_line
*/

#include "../../include/my.h"
#include <criterion/criterion.h>

int check_if_last_line(matchstick_t *ms, int *line, int *matches);

Test(check_if_last_line, return_1_again)
{
    matchstick_t ms;

    ms.max_matches = 3;
    ms.board = malloc(sizeof(char *) * (4 + 1));

    ms.board[0] = "*****\n";
    ms.board[1] = "*   *\n";
    ms.board[2] = "*|||*\n";
    ms.board[3] = "*****\n";
    ms.board[4] = NULL;
    int line = 0;
    int matches = 1;

    cr_assert_eq(check_if_last_line(&ms, &line, &matches), 1);
}