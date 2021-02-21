/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_bot_turn
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void initialise_board(matchstick_t *ms)
{
    ms->max_matches = 3;
    ms->board = malloc(sizeof(char *) * (4 + 1));
    ms->board[0] = "*****\n";
    ms->board[1] = malloc(sizeof(char) * 7);
    ms->board[1][0] = '*';
    ms->board[1][1] = ' ';
    ms->board[1][2] = '|';
    ms->board[1][3] = ' ';
    ms->board[1][4] = '*';
    ms->board[1][5] = '\n';
    ms->board[1][6] = 0;
    ms->board[2] = "*|||*\n";
    ms->board[3] = "*****\n";
    ms->board[4] = NULL;
    ms->line = 1;
    ms->max_matches = 100;
}

Test(bot_turn, print_msgs)
{
    char *res =
    "\nAI's turn...\nAI removed 1 match(es) from line 1\n*****   *|||";
    matchstick_t ms;

    initialise_board(&ms);

    cr_redirect_stdout();
    bot_turn(&ms);
    cr_assert_stdout_eq_str(res);

    free(ms.board);
    free(ms.board[1]);
}