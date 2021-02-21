/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** factorial with recursive
*/

int my_compute_factorial_rec(int nb)
{
    int result;

    if (nb < 0 || nb >= 13) {
        return (0);
    }
    if (nb == 1 || nb == 0) {
        return (1);
    }
    if (nb > 0) {
        result = nb * my_compute_factorial_rec(nb - 1);
        return (result);
    }
    return (0);
}
