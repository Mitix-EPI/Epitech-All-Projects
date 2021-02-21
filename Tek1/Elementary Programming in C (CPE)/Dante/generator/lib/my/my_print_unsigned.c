/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_unsigned
*/

#include <stdarg.h>

void my_putchar(char c);

int my_put_unsigned(unsigned int result)
{
    if (result >= 10) {
        my_put_unsigned(result / 10);
        my_putchar(result % 10 + '0');
    }
    else
        my_putchar(result + '0');
    return 0;
}

void my_print_unsigned(va_list ap, int test, char thing, int *n)
{
    unsigned int result;
    unsigned int tempo;
    int len = 0;

    result = va_arg(ap, unsigned int);
    tempo = result;
    while (tempo > 0) {
        tempo = tempo / 10;
        len += 1;
    }
    *n += len;
    for (int i = 0; i + len < test; i += 1)
        my_putchar(thing);
    my_put_unsigned(result);
}