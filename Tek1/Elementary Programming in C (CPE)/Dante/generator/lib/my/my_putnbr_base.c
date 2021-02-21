/*
** EPITECH PROJECT, 2019
** put nbr base
** File description:
** base n
*/

int my_strlen(char const *str);

void my_putchar(char c);

void my_putnbr_base(unsigned int nbr, char const *base)
{
    unsigned int basi = my_strlen(base);
    if (nbr >= basi)
        my_putnbr_base(nbr/basi, base);
    nbr = nbr % basi;
    my_putchar(base[nbr]);
}