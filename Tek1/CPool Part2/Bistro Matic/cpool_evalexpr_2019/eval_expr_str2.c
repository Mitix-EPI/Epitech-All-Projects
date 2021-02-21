/*
** EPITECH PROJECT, 2019
** eval_expr_str2.c
** File description:
** eval expr str v2
*/

#include <stdlib.h>
#include "../include/bistromatic.h"

static char const *x;
static int lenx;

char *infin_add(char *str1, char *str2);

char *my_parse_sum(void);

char *my_parse_product(void);

char *my_parse_factor(void);

int my_strlen(char const *str);

char *my_parse_sum(void)
{
    int choice = 0;
    char *pro2;
    char *pro1 = my_parse_product();

    while (*x == '+' || *x == '-') {
        if (*x == '+')
            choice = 0;
        if (*x == '-')
            choice = 1;
        ++x;
        pro2 = my_parse_product();
        if (choice == 0)
            pro1 = infin_add(pro1, pro2);
        if (choice == 1) {
            pro1 = infin_sub(pro1, pro2);
        }
    }
    return (pro1);
}

char *my_parse_product(void)
{
    char *res;
    int choice = 0;
    char *fac2;
    char *fac1 = my_parse_factor();

    while (*x == '*' || *x == '/' || *x == '%') {
        my_putstr_error("COMING SOON");
        exit(EXIT_BASE);
        if (*x == '/')
            choice = 0;
        if (*x == '%')
            choice = 0;
        ++x;
        fac2 = my_parse_factor();
        if (choice == 0) {
            exit(EXIT_BASE);
        }
    }
    return (fac1);
}

char *my_parse_factor(void)
{
    char *res_fac = malloc(sizeof(char) * (lenx * 2) + 1);
    char *other_res;

    if (*x >= '0' && *x <= '9' || *x == '-') {
        for (int i = 0; *x >= '0' && *x <= '9'; i++) {
            res_fac[i] = *x;
            ++x;
        }
        return (res_fac);
    }
    else if (*x == '(') {
        ++x;
        other_res = my_parse_sum();
        ++x;
        return (other_res);
    }
}

char *eval_expr1(char const *str)
{
    x = str;
    lenx = my_strlen(str);
    return (my_parse_sum());
}