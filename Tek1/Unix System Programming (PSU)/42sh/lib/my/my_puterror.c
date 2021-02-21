/*
** EPITECH PROJECT, 2019
** my_puterror
** File description:
** Display a string on error output
*/

#include "my.h"

int my_putchar(char c);

int    my_puterror(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
    return (0);
}
