/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** allez hop
*/

void my_putchar(char c);

int my_putstr(char const *);

int    my_put_nbr(int nb)
{
    if (nb == -2147483648)
        my_putstr("-2147483648");
    if (nb < 0 && nb != -2147483648) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    else if (nb != -2147483648)
        my_putchar(nb + '0');

    return (0);
}