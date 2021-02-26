/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** my_ftoa
*/

#include "needforspeed.h"

void reverse(char *str, int len)
{
    int i = 0;
    int j = len - 1;
    int temp = 0;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int inttostr(int x, char *str, int d)
{
    int i = 0;

    if (x < 0)
        x = -x;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    while (i < d)
        str[i++] = '0';
    reverse(str, i);
    str[i] = '\0';
    return i;
}

void my_putstr(int a, char const *str)
{
    int i = 0;

    while (str[i]) {
        write(a, &str[i], 1);
        i++;
    }
}

void my_ftoa(float n, char *res, int afterpoint)
{
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = inttostr(ipart, res, 0);

    if (n < 0) {
        res[i] = '-';
        i++;
    }

    if (afterpoint != 0) {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        inttostr((int)fpart, res + i + 1, afterpoint);
    }
}
