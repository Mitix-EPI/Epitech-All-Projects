/*
** EPITECH PROJECT, 2019
** my_gcvt
** File description:
** transform an int into a string given as argument
*/

#include <stdlib.h>

int get_nb_digit(int);

static int power10(int n)
{
    int x = 1;

    for (; n > 1 ; --n)
        x *= 10;
    return (x);
}

void my_itoa(char *str, int x)
{
    int i = 0;
    int dg = get_nb_digit(x);

    if (!str)
        return;
    for (int j = 0 ; str[j] && j < dg + 1 ; ++j)
        str[j] = '\0';
    if (x < 0) {
        str[0] = '-';
        x = -x;
        i += 1;
    }
    for (int j = 0 ; j < dg ; ++j) {
        str[i] = (x / power10(dg - j)) % 10 + '0';
        ++i;
    }
}