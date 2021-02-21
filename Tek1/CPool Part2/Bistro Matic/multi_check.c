/*
** EPITECH PROJECT, 2019
** multi_check.c
** File description:
** file where are the majority of check
*/

#include <stdlib.h>
#include "include/bistromatic.h"

void check_last_charac(char *expr)
{
    if (check_opr(expr[my_strlen(expr)-1]) || expr[my_strlen(expr)-1] == '-') {
        my_putstr_error(ERROR_MSG);
        exit(EXIT_USAGE);
    }
}