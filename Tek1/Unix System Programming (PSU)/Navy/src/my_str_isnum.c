/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** return value
*/

int my_char_isnum(char c)
{
    if (c < 48 || c > 57)
        return (1);
    else
        return (0);
}
