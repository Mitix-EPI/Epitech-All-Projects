/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_show_char
*/
#include <stdarg.h>

int my_showstr(char const *);

int my_strlen(char const *);

void my_putchar(char);

void my_print_show_char(va_list ap, int test, char thing, int *n)
{
    char *result;
    char *tempo;
    int len = 0;

    result = va_arg(ap, char *);
    tempo = result;
    len = my_strlen(tempo) + 1;
    *n += len;
    for (int i = 0; i + len < test; i += 1)
        my_putchar(thing);
    my_showstr(result);
}