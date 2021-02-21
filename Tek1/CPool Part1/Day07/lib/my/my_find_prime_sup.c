/*
** EPITECH PROJECT, 2019
** my_find_prime_sup.c
** File description:
** prime sup
*/

int my_find_prime_sup1(int nb)
{
    int first_number = 2;
    int res = 0;

    if (nb <= 1 || nb < 0)
        return (0);
    if (nb == 3 || nb == 5 || nb == 2)
        return (1);
    if (nb == 7)
        return (1);
    while (first_number <= 9){
        if (nb % first_number == 0)
            return (0);
        else {
            res = 1;
        }
        first_number++;
    }
    return (res);
}

int my_find_prime_sup(int nb)
{
    int nb_sup = nb - 1;
    int res = 0;

    while (res == 0){
        nb_sup++;
        res = my_find_prime_sup1(nb_sup);
    }
    return (nb_sup);
}
