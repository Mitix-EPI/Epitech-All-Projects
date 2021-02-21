/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** user
*/

#include "../include/my.h"

int loop(matchstick_t *ms, char *buff_size, char *buff_matchsticks)
{
    for (size_t size_buff = 4096, tmp = 0, tmp2 = 0; ms->max_matches;) {
        tmp = 0;
        write(1, "Line: ", 6);
        if (getline(&buff_size, &size_buff, stdin) == EOF)
            return (end_retur_n(buff_size, buff_matchsticks, ms->board, 1));
        tmp = my_getnbr(buff_size);
        if (check_line_selected(ms, tmp)) {
            write(1, "Matches: ", 9);
            if (getline(&buff_matchsticks, &size_buff, stdin) == EOF)
                return (end_retur_n(buff_size, buff_matchsticks, ms->board, 1));
            tmp2 = my_getnbr(buff_matchsticks);
            if (check_matches_selected(ms, tmp2, tmp) == 1) {
                ms->line_selected = tmp;
                ms->matches_selected = tmp2;
                return (0);
            }
        }
    }
    return (0);
}

int get_line_matches(matchstick_t *ms)
{
    char *buff_size = malloc(sizeof(char) * (4096 + 1));
    char *buff_matchsticks = malloc(sizeof(char) * (4096 + 1));
    if (loop(ms, buff_size, buff_matchsticks))
        return (1);
    return (end_retur_n(buff_matchsticks, buff_size, ms->board, 0));
}

void print_message(int line, int matches)
{
    write(1, "Player removed ", 15);
    my_put_nbr(matches);
    write(1, " match(es) from line ", 21);
    my_put_nbr(line);
    write(1, "\n", 1);
}

void update_map(char **board, int line, int matches)
{
    int x = 0;

    for (x = 0; board[line][x] != '|'; x++);
    for (; board[line][x] != ' ' && board[line][x] != '*'; x++);
    x -= 1;
    for (int i = 1; i <= matches; i++, x--)
        board[line][x] = ' ';
}

int user_turn(matchstick_t *ms)
{
    ms->end_res = 2;
    write(1, "\nYour turn:\n", 12);
    if (get_line_matches(ms))
        return (1);
    update_map(ms->board, ms->line_selected, ms->matches_selected);
    print_message(ms->line_selected, ms->matches_selected);
    print_map(ms);
    return (0);
}