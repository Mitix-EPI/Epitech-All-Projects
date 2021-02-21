/*
** EPITECH PROJECT, 2019
** check_existing_charac.c
** File description:
** check if all characters are in arguments
*/

#include "include/bistromatic.h"
#include <stdlib.h>

int check_charac_base_ops(char c, char *base, char *ops)
{
    for (int i = 0; base[i]; i++) {
        if (base[i] == c)
            return (0);
    }
    for (int j = 0; ops[j]; j++) {
        if (ops[j] == c)
            return (0);
    }
    return (1);
}

void check_existing_charac(char *expr, char *base, char *ops)
{
    for (int i = 0; expr[i]; i++) {
        if (check_charac_base_ops(expr[i], base, ops)) {
            my_putstr_error(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
}