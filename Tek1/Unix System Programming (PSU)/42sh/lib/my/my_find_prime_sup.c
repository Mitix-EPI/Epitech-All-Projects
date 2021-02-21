/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Return the smallest prime number that is greather than or equal
*/

int my_is_prime(int);

int    my_find_prime_sup(int nb)
{
    int i = nb;
    int prime_nb = 0;

    while (prime_nb == 0) {
        if (my_is_prime(i) == 1) {
            prime_nb = i;
        } else {
            i++;
        }
    }
    return (prime_nb);
}
