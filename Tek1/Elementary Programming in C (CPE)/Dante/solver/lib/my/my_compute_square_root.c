/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** ouais
*/

int    my_compute_square_root(int nb)
{
    int a = 0;

    while (a*a < nb)
        a++;
    if (a*a > nb)
        return 0;
    if (a * a == nb)
        return a;

    return (0);
}
