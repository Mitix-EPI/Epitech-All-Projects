/*
** EPITECH PROJECT, 2019
** infin_sub.c
** File description:
** sub two arguments infini
*/

#include "../include/bistromatic.h"

char *infin_sub(char *pro1, char *pro2)
{
    char *res;

    if (pro1[0] == '-' && pro2[0] == '-') {
        my_revstr(pro1);
        my_revstr(pro2);
        pro1[my_strlen(pro1)] = '-';
        pro2[my_strlen(pro2)] = '-';
        my_revstr(pro1);
        my_revstr(pro2);
    }
    else {
        my_revstr(pro2);
        pro2[my_strlen(pro2)] = '-';
        my_revstr(pro2);
    }
    res = infin_add(pro1, pro2);
    return (res);
}