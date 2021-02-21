/*
** EPITECH PROJECT, 2019
** find prime superior
** File description:
** finder of prime number
*/

int my_is_prime(int nb);

int    my_find_prime_sup(int nb)
{
    int test = 0;

    while (test != 1) {
        my_is_prime(nb);
        nb++;
    }
    return (nb);
}
