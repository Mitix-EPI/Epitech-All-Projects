/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** return value
*/

int my_isnumb(char const c)
{
    if ((c >= '0' && c <= '9') || c == '\n')
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int signe = 1;
    int a = 0;
    int res = 0;

    if (str[0] == ' ' || my_isnumb(str[0]) == 0)
        return (-84);
    for (int i = 0; str[i] && str[i] != '\n'; i++) {
        if (my_isnumb(str[i]) == 0)
            return (-84);
        if (str[0] < '0' || str[0] > '9')
            if ((str[i-1] == '-') && (a == 0)) {
                signe = -1;
                a = 1;
            }
        res = (res * 10) + (str[i] - 48);
    }
    res = res * signe;
    return (res);
}