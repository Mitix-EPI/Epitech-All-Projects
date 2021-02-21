/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printf funcs 2
*/

#include <stdarg.h>
#include "my.h"

int number_to_octal(int);
int my_put_octal_number(int);

char    *print_octal(va_list ap)
{
    my_put_nbr(number_to_octal(va_arg(ap, int)));
    return (NULL);
}

char    *print_hexa(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
    return (NULL);
}

char    *print_unsigned(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    my_put_nbr_unsigned(nb);
    return (NULL);
}

char    *print_upper_hexa(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
    return (NULL);
}

char    *print_binary(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
    return (NULL);
}
