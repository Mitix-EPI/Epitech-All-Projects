/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_hexa_capitalize
*/

#include <stdarg.h>

int my_putnbr_base(int nbr, char const *base);

void my_putchar(char);

void my_print_hexa_capitalize(va_list ap, int test, char thing, int *n)
{
    int len = 0;
    int result;
    int tempo;

    result = va_arg(ap, int);
    tempo = result;
    while (tempo > 0) {
        tempo = tempo / 16;
        len += 1;
    }
    *n += len;
    for (int i = 0; i + len < test; i += 1)
        my_putchar(thing);
    my_putnbr_base(result, "0123456789ABCDEF");
}