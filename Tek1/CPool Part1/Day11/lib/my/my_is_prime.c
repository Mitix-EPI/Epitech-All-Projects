/*
** EPITECH PROJECT, 2019
** my_is_prime.c
** File description:
** does the number is prime ?
*/

int my_is_prime(int nb)
{
    int first_numbers = 1;
    int res = 0;

    if (nb <= 1 || nb < 0)
        return (0);
    if (nb == 3 || nb == 5 || nb == 7)
        return (1);
    if (nb == 2)
        return (1);
    while (first_numbers <= 9){
        if (nb % first_numbers == 0){
            return (0);
        }
        else {
            res = 1;
        }
        first_numbers++;
    }
    return (res);
}
