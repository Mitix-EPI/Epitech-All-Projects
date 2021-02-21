/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** main
*/

#include "include/my.h"
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static array_t func[] =
{
    {'s', is_str},
    {'d', is_nbr},
    {'i', is_nbr},
    {'c', is_char},
    {'x', is_hex},
    {'p', is_ptr},
    {'X', is_hex_maj},
    {'b', is_bin},
    {'o', is_oct},
    {'u', is_notneg},
    {'%', is_percentage},
    {'a', is_array},
    {'t', is_int_star},
    {'r', is_raimbow_str}
};

void boucle(char const *format, va_list ap)
{
    int ch = 0;
    for (int i = 0; i < 14; i++)
        if (*format == func[i].c) {
            func[i].ptr(ap);
            ch = 1;
        }
    if (ch == 0) {
        my_putchar('%');
        my_putchar(*format);
    }
}

int my_printf(char const *format, ...)
{
    va_list ap;

    check_if_h(format);
    va_start(ap, format);
    for (; *format != '\0'; format++) {
        if (*format == '%') {
            format++;
            for (; *format == ' '; format++);
            boucle(format, ap);
        } else
            my_putchar(*format);
    }
    va_end(ap);
    return (1);
}