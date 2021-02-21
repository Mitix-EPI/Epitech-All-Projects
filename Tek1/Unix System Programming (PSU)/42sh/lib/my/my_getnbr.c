/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Return number, sent as a string
*/

int    check_negative(char c)
{
    if (c == '-')
        return (1);
    return (0);
}

int    make_negative(int negative, int nb)
{
    if (negative == 1)
        nb = nb * (-1);
    return (nb);
}

int    my_getnbr(char const *str)
{
    int negative = 0;
    int nb = 0;
    long long nb_long = 0;

    while (*str != '\0') {
        if ((*str == '+' || *str == '-') && nb == 0) {
            negative = check_negative(*str);
        } else if (*str >= '0' && *str <= '9') {
            if (nb * 10 + (*str - '0') != nb_long * 10 + (*str - '0'))
                return (0);
            nb = nb * 10 + (*str - '0');
            nb_long = nb_long * 10 + (*str - '0');
        } else if (nb == 0) {
            return (0);
        } else {
            break;
        }
        str++;
    }
    return (make_negative(negative, nb));
}
