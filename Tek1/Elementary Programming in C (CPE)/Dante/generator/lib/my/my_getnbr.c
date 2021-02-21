/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** getnbr
*/

int    my_getnbr(char const *str)
{
    int sum = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = sign * -1;
        i += 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            sum = (sum * 10) + (str[i] - '0');
            i += 1;
        } else if (sum == 2147483647)
            return 0;
        else
            return (sum * sign);
    }
    return (sum * sign);
}
