/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Print any int
*/

int    my_putchar(char c);

int    my_put_nbr(int nb)
{
    unsigned int n2;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        n2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_put_nbr(n2);
    } else {
        nb = nb + 48;
        my_putchar(nb);
    }
    return (0);
}

int    my_put_nbr_unsigned(unsigned int nb)
{
    unsigned int n2;

    if (nb > 9) {
        n2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_put_nbr(n2);
    } else {
        nb = nb + 48;
        my_putchar(nb);
    }
    return (0);
}