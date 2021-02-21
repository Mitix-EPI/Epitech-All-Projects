/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** checks
*/

#include "../include/my.h"

int check(int argc, char *argv, sokoban_t *s)
{
    int count_p = 0;
    if (argc > 2)
        return (1);
    for (int i = 0; argv[i]; i++) {
        if (argv[i] != '#' && argv[i] != 'P' && argv[i] != 'O')
            if (argv[i] != '\n' && argv[i] != 'X' && argv[i] != ' ')
                return (1);
        if (argv[i] == 'P')
            count_p += 1;
    }
    if (count_p != 1)
        return (1);
    s->stra = my_str_to_word_array(argv);
    return (0);
}

int check_0(sokoban_t *s)
{
    int res = 0;
    for (int i = 0; i < s->nb_o; i++) {
        if (s->s_mod[s->o_index[i][0]][s->o_index[i][1]] == 'X')
            res += 1;
    }
    if (res == s->nb_o)
        return (1);
    else
        return (0);
}

void check_pos_o(sokoban_t *s)
{
    for (int i = 0; i < s->nb_o; i++) {
        if (s->s_mod[s->o_index[i][0]][s->o_index[i][1]] == ' ')
            s->s_mod[s->o_index[i][0]][s->o_index[i][1]] = 'O';
    }
}

void check_sh(sokoban_t *s, char *map)
{
    s->ch = getch();
    if (s->ch == 32) {
        s->s_mod = my_str_to_word_array(map);
        print_map(s);
    }
}