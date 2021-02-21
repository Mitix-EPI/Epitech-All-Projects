/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** checks
*/

#include "../include/my.h"

int checks_buff_size(char *buffer, matchstick_t *ms)
{
    ms->line = 0;
    ms->line = my_getnbr(buffer);

    if (ms->line > 0 && ms->line <= 100)
        return (1);
    write(1, "Error: this line is out of range\n", 33);
    return (0);
}

int checks_buff_max_matchsticks(char *buffer, matchstick_t *ms)
{
    ms->max_matches = my_getnbr(buffer);

    if (ms->max_matches > 0)
        return (1);
    write(1, "Error: this line is out of range\n", 33);
    return (0);
}