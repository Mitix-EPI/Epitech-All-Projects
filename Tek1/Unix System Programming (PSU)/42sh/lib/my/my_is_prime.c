/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Return 1 if the number is prime and 0 if not
*/

int    my_is_prime(int nb)
{
    int i = 2;

    if (nb < 2)
        return (0);
    while (i < nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
