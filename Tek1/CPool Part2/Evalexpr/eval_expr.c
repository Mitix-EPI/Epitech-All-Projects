/*
** EPITECH PROJECT, 2019
** eval_expr.c
** File description:
** return result of the str calcul
*/

#include <stdio.h>
#include "include/my.h"

static char const *x;

int my_atoi(void)
{
    int nbr = 0;

    while (*x >= '0' && *x <= '9') {
        nbr = nbr * 10 + (*x - '0');
        x++;
    }
    return (nbr);
}

int my_parse_sum(void)
{
    int choice = 0;
    int pro2 = 0;
    int pro1 = my_parse_product();

    while (*x == '+' || *x == '-') {
        if (*x == '-')
            choice = 1;
        ++x;
        pro2 = my_parse_product();
        if (choice == 0)
            pro1 = pro1 + pro2;
        if (choice == 1)
            pro1 = pro1 - pro2;
    }
    return (pro1);
}

int my_parse_product(void)
{
    int choice = 0;
    int fac1 = my_parse_factor();
    int fac2 = 0;

    while (*x == '*' || *x == '/' || *x == '%') {
        if (*x == '/')
            choice = 1;
        if (*x == '%')
            choice = 2;
        ++x;
        fac2 = my_parse_factor();
        if (choice == 0)
            fac1 = fac1 * fac2;
        if (choice == 1)
            fac1 = fac1 / fac2;
        if (choice == 2)
            fac1 = fac1 % fac2;
    }
    return (fac1);
}

int my_parse_factor(void)
{
    int nb = 0;
    int sum = 0;
    int signe = 1;

    if (*x >= '0' && *x <= '9' || *x == '-') {
        if (*x == '-') {
            signe = -1;
            ++x;
        }
        nb = signe * my_atoi();
        return (nb);
    }
    else if (*x == '(') {
        ++x;
        sum = my_parse_sum();
        ++x;
        return (sum);
    }
}

int eval_expr(char const *str)
{
    x = str;
    return (my_parse_sum());
}