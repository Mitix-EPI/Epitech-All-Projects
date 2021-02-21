/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_pointer_adress
*/

#include <stdarg.h>
#include <string.h>

void my_putchar(char c);

int my_strlen(char const *);

void my_put_long(long long result, char const *base)
{
    int len = my_strlen(base);
    if (result >= len)
        my_put_long(result/len, base);
    result = result % len;
    my_putchar(base[result]);
}

void my_print_pointer_adress(va_list ap, int test, char thing, int *n)
{
    long long result;
    long long tempo;
    int len = 0;

    result = va_arg(ap, long long);
    tempo = result;
    while (tempo > 0) {
        tempo = tempo / 10;
        len += 1;
    }
    *n += len;
    for (int i = 0; i + len < test; i += 1)
        my_putchar(thing);
    my_putchar('0');
    my_putchar('x');
    my_put_long(result, "0123456789abcdef");
}