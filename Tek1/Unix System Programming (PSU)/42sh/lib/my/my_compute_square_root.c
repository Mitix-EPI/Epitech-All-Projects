/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Return the square root
*/

int    my_compute_square_root(int nb)
{
    int n = 0;

    if (nb == 0 || nb < 0)
        return (0);
    while (nb != n * n) {
        n++;
        if (n > nb)
            return (0);
    }
    return (n);
}
