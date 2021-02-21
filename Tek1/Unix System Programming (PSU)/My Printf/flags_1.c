/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** flags_1
*/

#include "include/my.h"

void is_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void is_str(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void is_nbr(va_list ap)
{
    my_put_nbr(va_arg(ap, long long));
}

void is_ptr(va_list ap)
{
    my_putstr("0x");
    my_put_nbr_base(va_arg(ap, long long), "0123456789abcdef");
}

void is_hex(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
}