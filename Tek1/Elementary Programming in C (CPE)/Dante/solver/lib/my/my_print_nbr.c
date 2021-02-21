/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_nbr
*/

#include <stdarg.h>

int my_put_nbr(int nb);

void my_putchar(char);

void my_print_nbr(va_list ap, int test, char thing, int *n)
{
    int result;
    int tempo;
    int len = 0;

    result = va_arg(ap, int);
    tempo = result;
    while (tempo > 0) {
        tempo = tempo / 10;
        len += 1;
    }
    *n += len;
    for (int i = 0; i + len < test; i += 1) {
        my_putchar(thing);
    }
    my_put_nbr(result);
}