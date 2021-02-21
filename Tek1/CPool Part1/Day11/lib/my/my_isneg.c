/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** display negative or positif
*/

#include <unistd.h>

int my_isneg(int n)
{
    int positive_or_null = 80;
    int negative = 78;

    if (n >= 0){
        write(1, &positive_or_null, 1);
    }
    else {
        write (1, &negative, 1);
    }
    return (0);
}
