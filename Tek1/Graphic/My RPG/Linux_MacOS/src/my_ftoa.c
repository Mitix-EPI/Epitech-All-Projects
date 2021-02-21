/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_ftoa
*/

#include "rpg.h"

void reverse(char *str, int len)
{
    int i = 0, j = len - 1, temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(int x, char *str, int d)
{
    int i = 0;

    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return (i);
}

char *ftoa(float n, int afterpoint)
{
    char *res = malloc(sizeof(char) * ((int)n));
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = intToStr(ipart, res, 0);

    if (afterpoint != 0) {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
    return (res);
}
