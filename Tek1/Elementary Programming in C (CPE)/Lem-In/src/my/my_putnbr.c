/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** my_putnbr
*/

#include <unistd.h>

void my_putnbr(int nb)
{
    char c;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0) {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        c = nb + '0';
        write(1, &c, 1);
    }
}
