/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print_len
*/

#include <stdarg.h>

void my_print_len(va_list ap, int test, char thing, int *n)
{
    int *result;
    int arn = 0;

    if (test == 69 || thing == 69)
        arn = 1;
    if (arn == 1)
        arn = 0;
    result = va_arg(ap, int *);
    *n -= 1;
    *result = *n;
}