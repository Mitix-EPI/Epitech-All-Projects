/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** put numbers
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    char moins = '-';
    int number;

    if (nb < 0){
        write(1, &moins, 1);
        nb = nb * (-1);
    }
    if (nb > 10){
        number = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_put_nbr(number);
    }
    else {
        nb = nb + 48;
        write(1, &nb, 1);
    }
    return (0);
}
