/*
** EPITECH PROJECT, 2019
** my_str_is_alpha
** File description:
** Function
*/

#include "../include/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] >= 'A' && str[i] <= 'H'))
            return (0);
        i += 1;
    }
    return (1);
}

int my_char_isalpha(char c)
{
    if ((c >= 'A' && c <= 'H'))
        return (1);
    else
        return (0);
}
