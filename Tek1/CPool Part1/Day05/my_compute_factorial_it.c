/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it.c
** File description:
** factorial with iterative fonction
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb >= 13 || nb < 0){
        return (0);
    }
    if (nb == 0){
        return (1);
    }
    while (nb > 1){
        result = result * (nb);
        nb = nb - 1;
    }
    return (result);
}
