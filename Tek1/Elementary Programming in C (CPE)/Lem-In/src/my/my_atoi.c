/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Convert a string into an integer
*/

#include <stdio.h>

int my_atoi(const char *str)
{
    __int8_t sign = 1;
    int res = 0;
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] && str[i] != '-' && (str[i] < '0' || str[i] > '9') ; ++i);
    if (str[i] == '-') {
        sign = -1;
        ++i;
    }
    for (; str[i] && (str[i] >= '0' && str[i] <= '9') ; ++i)
        res = res * 10 + str[i] - '0';
    return (sign * res);
}