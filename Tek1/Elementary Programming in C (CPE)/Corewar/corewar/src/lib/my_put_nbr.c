/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** function to display number
*/

void my_putchar(const int fd, char c);

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_put_nbr(nb);
        my_putchar(1, '-');
    } else if (nb != 0) {
        my_put_nbr(nb / 10);
        my_putchar(1, (nb % 10) + '0');
    }
}