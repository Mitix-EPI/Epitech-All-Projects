/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** return value
*/

int my_isnumb(char const c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int signe = 1;
    int a = 0;
    int j;
    int res = 0;

    for (j = 0; !my_isnumb(str[j]); j++);
    for (int i = j; my_isnumb(str[i]); i++) {
        if ((str[i-1] == '-') && (a == 0)) {
            signe = -1;
            a = 1;
        }
        res = (res * 10) + (str[i] - 48);
    }
    res = res * signe;
    return (res);
}