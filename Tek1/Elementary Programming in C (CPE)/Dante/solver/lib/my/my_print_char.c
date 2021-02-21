/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_char
*/

#include <stdarg.h>

void my_putchar(char);

void my_print_char(va_list ap, int test, char thing, int *n)
{
    char result;
    result = va_arg(ap, int);
    if (test != 0) {
        for (int i = 0; i < test; i += 1)
            my_putchar(thing);
    }
    *n += 1;
    my_putchar(result);
}