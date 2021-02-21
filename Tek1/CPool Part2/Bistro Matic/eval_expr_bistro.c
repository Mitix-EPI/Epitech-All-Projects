/*
** EPITECH PROJECT, 2019
** eval_expr_empty.c
** File description:
** function empty
*/

#include "include/bistromatic.h"
#include <stdlib.h>
#include <stdio.h>

int check_para(char *expr, char const *ops)
{
    int number_para_1 = 0;
    int number_para_2 = 0;

    for (int i = 0; expr[i]; i++) {
        if (expr[i] == ops[0])
            number_para_1 = number_para_1 + 1;
        if (expr[i] == ops[1])
            number_para_2 = number_para_2 + 1;
    }
    if (number_para_1 != number_para_2) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int return_ops(int j)
{
    if (j == 0)
        return ('(');
    if (j == 1)
        return (')');
    if (j == 2)
        return ('+');
    if (j == 3)
        return ('-');
    if (j == 4)
        return ('*');
    if (j == 5)
        return ('/');
    if (j == 6)
        return ('%');
}

char *translate(char const *base, char const *ops, char const *expr, char *str)
{
    int i = 0;

    for (i; expr[i] != '\0'; i++) {
        for (int j = 0; base[j]; j++) {
            if (expr[i] == base[j]) {
                str[i] = j + '0';
            }
        }
        for (int j = 0; ops[j] != '\0'; j++) {
            if (expr[i] == ops[j]) {
                str[i] = return_ops(j);
            }
        }
    }
    str[i + 1] = '\0';
    return (str);
}

char *re_translate(char const *base, char *str, char *res, char const *ops)
{
    int i = 0;
    char *res_re_translate = res;
    char *cache;

    if (res_re_translate[0] == '0') {
        cache[0] = base[0];
        cache[1] = '\0';
        return (cache);
    }
    if (res_re_translate[0] == '-') {
        res_re_translate[0] = ops[3];
        i = 1;
    }
    for (i; res_re_translate[i] != '\0'; i++)
        for (int j = 0; base[j]; j++)
            if (res_re_translate[i] == (j + '0')) {
                res_re_translate[i] = base[j];
            }
    res_re_translate[i + 1] = '\0';
    return (res_re_translate);
}

char *eval_expr(char const *base, char const *ops, char *expr, int size)
{
    char *str = malloc(my_strlen(expr) + 1);
    char *res;

    translate(base, ops, expr, str);
    opeator_handling(str);
    check_last_charac(str);
    res = eval_expr1(str);
    return (re_translate(base, str, res, ops));
}