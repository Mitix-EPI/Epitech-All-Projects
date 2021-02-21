/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** flags_2
*/

#include "include/my.h"

void is_hex_maj(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
}

void is_bin(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "01");
}

void is_oct(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "01234567");
}

void is_notneg(va_list ap)
{
    unsignednbr(va_arg(ap, unsigned int));
}

void is_percentage(va_list ap)
{
    my_putchar('%');
}