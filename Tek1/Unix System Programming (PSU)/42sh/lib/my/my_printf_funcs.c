/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printf funcs
*/

#include <stdarg.h>
#include "my.h"

int my_putnbr_base_long(long, char const *);
int my_put_octal_number(int);
int number_to_octal(int);

char    *print_str(va_list ap)
{
    return (va_arg(ap, char *));
}

char    *print_char(va_list ap)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = va_arg(ap, int);
    str[1] = '\0';
    return (str);
}

char    *print_number(va_list ap)
{
    char *str = malloc(sizeof(int) + 9);

    my_memset(str, 0, sizeof(int) + 9);
    str = my_itoa(va_arg(ap, int));
    return (str);
}

char    *print_wide_string(va_list ap)
{
    char *str = va_arg(ap, char *);

    for (int i = 0; str[i]; i++)
        if (str[i] == 127 || str[i] < 32)
            my_put_octal_number(number_to_octal(str[i]));
        else
            my_putchar(str[i]);
    return (NULL);
}

char    *print_pointer(va_list ap)
{
    void *ptr = va_arg(ap, void *);
    void *p = &ptr;

    if (ptr == NULL)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_putnbr_base_long((long)ptr, "0123456789abcdef");
    }
    return (NULL);
}