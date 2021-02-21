/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** tests_check_if_last_line
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int check_if_last_line(matchstick_t *ms, int *line, int *matches);

Test(check_if_last_line, return_0)
{
    matchstick_t ms;
    ms.board = print_my_lucas(4);
    int line = 4;
    int matches = 4;

    cr_assert_eq(check_if_last_line(&ms, &line, &matches), 0);
    for (int i = 0; ms.board[i] != NULL; i++)
        free(ms.board[i]);
    free(ms.board);
}

Test(check_if_last_line, return_1)
{
    matchstick_t ms;
    char *array[3] = {"*   *\n", "*|||*\n", NULL};
    int line = 2;
    int matches = 4;

    ms.board = array;
    cr_assert_eq(check_if_last_line(&ms, &line, &matches), 1);
}