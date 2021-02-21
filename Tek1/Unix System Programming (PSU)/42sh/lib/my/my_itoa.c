/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** Convert number to string
*/

#include "my.h"

static char    *convert_digit(char *dest, int i)
{
    if (i <= -10)
        dest = convert_digit(dest, i / 10);
    *dest++ = '0' - i % 10;
    return (dest);
}

char    *my_itoa(int i)
{
    char *dest = malloc(sizeof(char) * 12);
    char *s = dest;

    dest = my_memset(dest, 0, sizeof(char) * 12);
    if (i < 0)
        *s++ = '-';
    else
        i = -i;
    *convert_digit(s, i) = '\0';
    return (dest);
}