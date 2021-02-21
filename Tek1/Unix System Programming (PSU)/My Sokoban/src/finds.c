/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** finds
*/

#include "../include/my.h"

void find_p(sokoban_t *s)
{
    for (int i = 0; s->s_mod[i] != NULL; i++)
        for (int j = 0; s->s_mod[i][j]; j++)
            if (s->s_mod[i][j] == 'P') {
                s->x = j;
                s->y = i;
            }
}

void find_o(sokoban_t *s)
{
    int r = 0;

    s->nb_o = 0;
    for (int i = 0; s->s_mod[i] != NULL; i++)
        for (int j = 0; s->s_mod[i][j]; j++)
            if (s->s_mod[i][j] == 'O')
                s->nb_o += 1;
    s->o_index = malloc(sizeof(s->o_index) * (s->nb_o + 1));
    for (int i = 0; i < s->nb_o; i++)
        s->o_index[i] = malloc(sizeof(s->o_index[i]) * (2 + 1));
    for (int i = 0; s->s_mod[i] != NULL; i++)
        for (int j = 0; s->s_mod[i][j]; j++)
            if (s->s_mod[i][j] == 'O') {
                s->o_index[r][0] = i;
                s->o_index[r][1] = j;
                r += 1;
            }
}

int check_htag(sokoban_t *s, int i, int j)
{
    if (s->s_mod[i][j] == 'X') {
        if (s->s_mod[i][j - 1] == '#' && s->s_mod[i - 1][j] == '#')
            return (1);
        if (s->s_mod[i][j - 1] == '#' && s->s_mod[i + 1][j] == '#')
            return (1);
        if (s->s_mod[i][j + 1] == '#' && s->s_mod[i + 1][j] == '#')
            return (1);
        if (s->s_mod[i][j + 1] == '#' && s->s_mod[i - 1][j] == '#')
            return (1);
    }
    return (0);
}

int find_hashtag(sokoban_t *s)
{
    int nb_hash = 0;
    int count = 0;

    for (int i = 0; s->s_mod[i] != NULL; i++)
        for (int j = 0; s->s_mod[i][j]; j++)
            if (s->s_mod[i][j] == 'X')
                nb_hash++;
    for (int i = 0; s->s_mod[i] != NULL; i++)
        for (int j = 0; s->s_mod[i][j]; j++)
            if (check_htag(s, i, j))
                count++;
    if (count == nb_hash)
        return (1);
    return (0);
}