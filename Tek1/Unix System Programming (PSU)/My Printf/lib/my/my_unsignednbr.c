/*
** EPITECH PROJECT, 2019
** unsignednbr.c
** File description:
** put numbers
*/

#include <unistd.h>

int unsignednbr(unsigned int nb)
{
    int number;

    if (nb >= 10){
        number = nb % 10;
        nb = nb / 10;
        unsignednbr(nb);
        unsignednbr(number);
    }
    else {
        nb = nb + 48;
        write(1, &nb, 1);
    }
    return (0);
}