/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Return the first argument raised to the power p (second argument)
*/

int    my_compute_power_rec(int nb, int p)
{
    if (p > 0)
        nb *= my_compute_power_rec(nb, p - 1);
    else if (p == 0)
        return (1);
    else
        return (0);
    return (nb);
}
