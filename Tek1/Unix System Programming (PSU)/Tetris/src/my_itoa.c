/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_itoa
*/

#include "../include/my.h"

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

char *my_itc(int nbr)
{
    int len = number_digits(nbr);
    char *result = malloc(sizeof(char) * len);
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}