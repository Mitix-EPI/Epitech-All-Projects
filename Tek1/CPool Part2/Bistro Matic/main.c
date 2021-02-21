/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/bistromatic.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * size + 1);
    if (expr == 0) {
        my_putstr_error(ERROR_MSG);
        free(expr);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr_error(ERROR_MSG);
        free(expr);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

static void check_ops(char const *ops)
{
    char c;

    if (my_strlen(ops) != 7) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i] != '\0'; i++) {
        c = ops[i];
        for (int j = 0; ops[j] != '\0'; j++) {
            if (ops[j] == c && j != i) {
                my_putstr_error(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
}

static void check_base(char const *b)
{
    char c;

    for (int i = 0; b[i] != '\0'; i++) {
        c = b[i];
        for (int j = 0; b[j] != '\0'; j++) {
            if (b[j] == c && j != i) {
                my_putstr_error(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
    if (my_strlen(b) != 10) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        if (ac == 2 && check_h(av[1]))
            exit(help());
        my_putstr_error(ERROR_MSG);
        exit(EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    check_existing_charac(expr, av[1], av[2]);
    check_expr_empty(expr);
    check_para(expr, av[2]);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    free(expr);
    return (EXIT_SUCCESS);
}