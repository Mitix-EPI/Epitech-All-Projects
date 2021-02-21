/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays one-by-one the characters of a string
*/

#include <unistd.h>
#include "bistromatic.h"

void my_putchar1(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar1(str[i]);
        i = i + 1;
    }
    return (0);
}