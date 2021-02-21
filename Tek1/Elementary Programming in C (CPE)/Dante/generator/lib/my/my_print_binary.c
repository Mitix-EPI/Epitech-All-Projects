/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_binary
*/

#include <stdarg.h>

int my_putnbr_base(unsigned int nbr, char const *base);

void my_putchar(char);

void my_print_binary(va_list ap, int test, char thing, int *n)
{
    unsigned int result;
    int len = 0;
    int tempo;

    result = va_arg(ap, unsigned int);
    tempo = result;
    while (tempo > 0) {
        tempo = tempo / 2;
        len += 1;
    }
    *n += len;
    for (int i = 0; i + len < test; i += 1)
        my_putchar(thing);
    my_putnbr_base(result, "01");
}