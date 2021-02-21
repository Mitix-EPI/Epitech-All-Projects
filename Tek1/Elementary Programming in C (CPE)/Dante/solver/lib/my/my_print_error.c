/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_print_error
*/

#include <stdarg.h>
#include <unistd.h>

int my_strlen(char const *);

void my_print_error(va_list ap, int test, char thing, int *n)
{
    char *result;
    char *tempo;
    int len = 0;

    result = va_arg(ap, char *);
    tempo = result;
    len = my_strlen(tempo) + 1;
    *n += len;
    for (int i = 0; i + len < test; i += 1)
        write(2, &thing, 1);
    for (int i = 0; result[i]; i += 1)
        write(2, &result[i], 1);
}