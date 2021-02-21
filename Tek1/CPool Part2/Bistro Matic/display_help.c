/*
** EPITECH PROJECT, 2019
** display_help.c
** File description:
** Displays help
*/

#include "include/bistromatic.h"
#include <stdlib.h>

int check_h(char *str)
{
    if (str[0] == '-' && str[1] == 'h' && my_strlen(str) == 2)
        return (1);
    else
        return (0);
}

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n");
    my_putstr("\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses and the ");
    my_putstr("5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return (EXIT_USAGE);
}

int check_opr(char c)
{
    if (c == '+' || c == '*' || c == '/')
        return (1);
    if (c == '%')
        return (1);
    return (0);
}

void opeator_handling(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i + 1 != '\0']; i++) {
        if (check_opr(str[i]) || str[i] == '-') {
            if (check_opr(str[i + 1]) == 1) {
                my_putstr_error(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
}

void check_expr_empty(char *expr)
{
    if (expr[0] == '\n') {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}