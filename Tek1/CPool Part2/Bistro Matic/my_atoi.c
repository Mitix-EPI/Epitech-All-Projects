/*
** EPITECH PROJECT, 2019
** check_sizeread.c
** File description:
** check size read of the calcul
*/

#include "include/bistromatic.h"
#include <stdlib.h>

int my_atoi(char *str)
{
    int nbr = 0;

    while (*str >= '0' && *str <= '9') {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }
    return (nbr);
}