/*
** EPITECH PROJECT, 2020
** structures prototypes
** File description:
** structures for asm
*/

#include "asm.h"

int count_args(char *ln, int args_count)
{
    int args = 0;

    printf("ln = %s, args_count = %d\n", ln, args_count);
    for (int i = 0; i < args_count; i++) {
        if (ln[0] != ',' && ln[0] != '\t' && ln[0] != ' ')
            args++;
        for (; ln[0] == ',' || ln[0] == '\t' || ln[0] == ' '; ln++);
        if (ln[0] == '\n' || ln[0] == '\0')
            break;
    }
    printf("arg = %d\n", args);
    if (args == args_count)
        return (1);
    return (0);
}

int check_args_count(char *ln)
{
    char **test = word_array(ln, (char []){'%', ':', '_', '\0'}, (char *[])\
    {"az", "09", NULL});
    int nb_args = 0;
    int size = 0;

    for (int i = 0; op_tab[i].mnemonique; i += 1)
        if (my_strcmp(test[0], op_tab[i].mnemonique) == 0)
            nb_args = op_tab[i].nbr_args;
    for (; test[size]; size += 1);
    size -= 1;
    if (size == nb_args)
        return (1);
    return (0);
}

int check_mnemonique(char *ln)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strncmp(op_tab[i].mnemonique, ln, \
        my_strlen(op_tab[i].mnemonique)) == 0) {
            return (1);
        }
    }
    return (0);
}

int line_parser(char *ln)
{
    int ret = 0;

    for (; ln[0] == '\t' || ln[0] == ' '; ln++);
    if (ret = check_label(ln)) {
        if (is_label_without_instruction(ln))
            return (0);
        for (int a = 0; a <= ret; a += 1, ln++);
        for (; ln[0] == '\t' || ln[0] == ' '; ln++);
    if (!check_mnemonique(ln))
        return (WRONG_INSTRUCTION);
    }
    for (; ln[0] == '\t' || ln[0] == ' '; ln++);
    if (!check_args_count(ln))
        return (NOT_ENOUGH_ARGUMENTS);
    for (; ln[0] == '\t' || ln[0] == ' '; ln++);
    if (!check_variable(ln))
        return (WRONG_VARIABLE_TYPE);
    return (0);
}
