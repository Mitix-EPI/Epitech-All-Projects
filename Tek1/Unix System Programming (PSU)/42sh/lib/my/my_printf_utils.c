/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Utils funcs for myprintf
*/

#include "my.h"

void my_put_octal_number(int nb)
{
    my_putchar('\\');
    for (int i = 1; nb * i < 100; i *= 10)
        my_putchar('0');
    my_put_nbr(nb);
}

int number_to_octal(int nb)
{
    int octal_nb = 0;

    for (int i = 1; nb != 0; i *= 10) {
        octal_nb += i * (nb % 8);
        nb /= 8;
    }
    return (octal_nb);
}

char    *str_move(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i+1];
    return (str);
}