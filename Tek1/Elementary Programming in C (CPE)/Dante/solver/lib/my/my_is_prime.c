/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** kdpa
*/

int    my_is_prime(int nb)
{
    int a = 2;

    if (nb == 0)
        return 0;
    if (nb == 1)
        return 0;

    while (a < nb) {
        if (nb % a == 0)
            return 0;
        a++;
    }

    return 1;
}
