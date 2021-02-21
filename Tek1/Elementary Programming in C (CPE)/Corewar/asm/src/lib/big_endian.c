/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** big_endian
*/

long int power(int nb, int nb_power)
{
    long int result = nb;

    if (nb_power != 1)
        result *= power(nb, nb_power - 1);
    return (result);
}

int little_to_big(int nb)
{
    int tmp = 0;

    tmp = (nb & 0xFF000000) / power(2, 24);
    tmp |= ((nb & 0x00FF0000) / power(2, 8));
    tmp |= ((nb & 0x0000FF00) * power(2, 8));
    tmp |= ((nb & 0x000000FF) * power(2, 24));
    return (tmp);
}