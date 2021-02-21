/*
** EPITECH PROJECT, 2019
** Lib
** File description:
** my_putnbr_base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int result = 0;
    int ret = 1;
    int base_len = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    while ((nbr / ret) >= base_len)
        ret *= base_len;
    for (; ret > 0; ret = ret / base_len) {
        result = (nbr / ret) % base_len;
        my_putchar(base[result]);
    }
    return (1);
}

int my_putnbr_base_long(long nbr, char const *base)
{
    int i = 0;
    int len = my_strlen(base);
    long nb;

    if (nbr < 0) {
        nbr = - nbr;
        i++;
        my_putchar('-');
    } else if (nbr != 0) {
        nb = nbr;
        nbr /= len;
        i += my_putnbr_base_long(nbr, base) + 1;
        my_putchar(base[nb % len]);
    }
    return (i);
}