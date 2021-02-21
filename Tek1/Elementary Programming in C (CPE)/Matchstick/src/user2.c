/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** user2
*/

#include "../include/my.h"

int check_existing_line(matchstick_t *ms, int tmp)
{
    for (int i = tmp; i <= tmp; i++)
        for (int y = 0; ms->board[i][y]; y++)
            if (ms->board[i][y] == '|')
                return (1);
    return (0);
}

int check_line_selected(matchstick_t *ms, int tmp)
{
    if (tmp == -84 || tmp < 0) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (0);
    }
    if (tmp <= ms->line && tmp > 0) {
        if (check_existing_line(ms, tmp)) {
            return (1);
        } else {
            write(1, "Error: Empty line\n", 18);
            return (0);
        }
    } else
        write(1, "Error: this line is out of range\n", 33);
    return (0);
}

int check_nb_matches(matchstick_t *ms, int line)
{
    int tmp = 0;

    for (int i = line; i <= line; i++)
        for (int y = 0; ms->board[i][y]; y++)
            if (ms->board[i][y] == '|')
                tmp += 1;
    return (tmp);
}

int check_matches_selected(matchstick_t *ms, int tmp, int line)
{
    int nb = 0;

    if (tmp == -84 || tmp < 0)
        return (prt_rtn("Error: invalid input (positive number expected)\n"));
    if (tmp == 0)
        return (prt_rtn("Error: you have to remove at least one match\n"));
    if (tmp > ms->max_matches) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(ms->max_matches);
        return (prt_rtn(" matches per turn\n"));
    }
    if (tmp > 0 && tmp <= ms->max_matches) {
        if ((nb = check_nb_matches(ms, line)) >= tmp) {
            return (1);
        } else {
            write(1, "Error: not enough matches in this line\n", 39);
        }
    } else
        write(1, "Error: argument not valid\n", 26);
    return (0);
}

int end_retur_n(char *str1, char *str2, char **array, int i)
{
    free(str1);
    free(str2);
    if (i == 1)
        for (int j = 0; array[j] != NULL; j++)
            free(array[j]);
    return (i);
}