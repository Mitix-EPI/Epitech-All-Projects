/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** main
*/

#include "menger.h"

int my_isnumb(char const c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int signe = 1;
    int a = 0;
    int j;
    int res = 0;

    for (j = 0; !my_isnumb(str[j]); j++);
    for (int i = j; my_isnumb(str[i]); i++) {
        if ((str[i-1] == '-') && (a == 0)) {
            signe = -1;
            a = 1;
        }
        res = (res * 10) + (str[i] - 48);
    }
    res = res * signe;
    return (res);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        return 84;
    }
    int sizeSquare = my_getnbr(av[1]);
    int nbLevel = my_getnbr(av[2]);
    if (sizeSquare <= 0 || sizeSquare % 3 == 1 || nbLevel <= 0) {
        return 84;
    }
    menger(sizeSquare, 0, 0, nbLevel);
    return 0;
}
