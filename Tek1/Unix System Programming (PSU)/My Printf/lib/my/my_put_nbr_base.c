/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_nbr_base
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_put_nbr_base(long long nb, char *base)
{
    char moins = '-';
    int number = 0;

    if (nb < 0){
        write(1, &moins, 1);
        nb = nb * (-1);
    }
    if (nb >= my_strlen(base)){
        number = nb % my_strlen(base);
        nb = nb / my_strlen(base);
        my_put_nbr_base(nb, base);
        my_put_nbr_base(number, base);
    }
    else {
        write(1, &base[nb], 1);
    }
    return (0);
}