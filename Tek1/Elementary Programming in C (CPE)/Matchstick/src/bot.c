/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** bot
*/

#include "../include/my.h"

int generate_random(int lower, int upper)
{
    return ((rand() % (upper - lower + 1)) + lower);
}

void print_ia_message(int line, int matches)
{
    write(1, "AI removed ", 11);
    my_put_nbr(matches);
    write(1, " match(es) from line ", 21);
    my_put_nbr(line);
    write(1, "\n", 1);
}

int check_if_last_line(matchstick_t *ms, int *line, int *matches)
{
    int booleen = 0;
    int count_line = 0;
    int good_line = 0;
    int m = 0;

    for (int i = 0; ms->board[i] != NULL; i++, booleen = 0) {
        for (int x = 0; ms->board[i][x]; x++)
            if (ms->board[i][x] == '|' && booleen == 0) {
                good_line = i;
                booleen = 1;
                count_line++;
            }
    }
    if (count_line == 1 && check_nb_matches(ms, good_line) > 1) {
        *line = good_line;
        m = check_nb_matches(ms, *line) - 1;
        if (m > ms->max_matches)
            *matches = ms->max_matches;
        else
            *matches = check_nb_matches(ms, *line) - 1;
        return (count_line);
    } else
        return (0);
}

void bot_turn(matchstick_t *ms)
{
    int line = 0;
    int matches = 0;

    ms->end_res = 1;
    write(1, "\nAI's turn...\n", 14);
    if (check_if_last_line(ms, &line, &matches) != 1) {
        while (1) {
            line = generate_random(1, ms->line);
            if (check_existing_line(ms, line) && line > 0)
                break;
        }
        while (1) {
            matches = generate_random(1, check_nb_matches(ms, line));
            if (matches <= check_nb_matches(ms, line) && matches > 0)
                break;
        }
    }
    update_map(ms->board, line, matches);
    print_ia_message(line, matches);
    print_map(ms);
}