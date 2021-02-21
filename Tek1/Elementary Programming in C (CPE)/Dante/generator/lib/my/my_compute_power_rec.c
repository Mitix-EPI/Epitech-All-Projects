/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** dansleportdalexandrie
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (nb < 0 || p < 0)
        return 0;
    nb = nb * my_compute_power_rec(nb, p - 1);
    return nb;
}
