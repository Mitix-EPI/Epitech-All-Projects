/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** main_name
*/

#include "../include/my.h"

int free_board(char **board)
{
    for (int i = 0; board[i] != NULL; i++)
        free (board[i]);
    free (board);
    return (0);
}

int check_stick(char **board)
{
    for (int i = 0; board[i] != NULL; i++)
        for (int y = 0; board[i][y]; y++)
            if (board[i][y] == '|')
                return (1);
    return (0);
}

int get_args(int ac, char **av, matchstick_t *ms)
{
    if (ac == 3) {
        ms->line = my_getnbr(av[1]);
        ms->max_matches = my_getnbr(av[2]);
        if (ms->line <= 1 || ms->line > 100 || ms->max_matches <= 0) {
            write(1, "Arguments need to be between 1 and 100", 38);
            return (1);
        }
    }
    return (0);
}

int main_matchstick(int ac, char **av)
{
    matchstick_t ms;

    if (get_args(ac, av, &ms) == 1)
        return (84);
    ms.board = print_my_lucas(ms.line);
    print_map(&ms);
    while (1) {
        if (user_turn(&ms))
            return (0);
        if (check_stick(ms.board) == 0)
            break;
        bot_turn(&ms);
        if (check_stick(ms.board) == 0)
            break;
    }
    print_end_msg(ms.end_res);
    free_board(ms.board);
    return (ms.end_res);
}