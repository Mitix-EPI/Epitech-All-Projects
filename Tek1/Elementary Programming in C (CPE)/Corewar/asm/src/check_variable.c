/*
** EPITECH PROJECT, 2020
** structures prototypes
** File description:
** structures for asm
*/

#include "asm.h"

int get_mnemonique(char *ln)
{
    char **test = word_array(ln, (char []){'%', ':', '_', '\0'}, \
    (char *[]){"az", "09", NULL});

    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(test[0], op_tab[i].mnemonique) == 0) {
            return (i);
        }
    }
}

int check_argument(int arg, int index_op, int i)
{
    int arg_op = op_tab[index_op].type[i];

    if (arg_op == 1 || arg_op == 2 || arg_op == 4 || arg_op == 7) {
        if (arg_op == 7)
            return (1);
        else if (arg_op == arg)
            return (1);
        return (0);
    }
    arg_op -= arg;
    if (arg_op == 1 || arg_op == 2 || arg_op == 4)
        return (1);
    return (0);
}

int get_type_argument(char c)
{
    if (c == 'r')
        return (1);
    if (c == '%')
        return (2);
    if (c != '#' && c)
        return (4);
    return (0);
}

int check_variable(char *ln)
{
    int index = get_mnemonique(ln);
    int nba = op_tab[index].nbr_args;
    int type = 0;

    for (int i = 0; i < nba; i++) {
        for (; (ln[0] != '\t' && ln[0] != ' ') && ln[0]; ln++);
        for (; (ln[0] == '\t' || ln[0] == ' ') && ln[0]; ln++);
        type = get_type_argument(ln[0]);
        if (!check_argument(type, index, i))
            return (0);
        if (type == 1 && (my_atoi(ln) <= 0 || my_atoi(ln) > 16))
            return (0);
    }
    return (1);
}