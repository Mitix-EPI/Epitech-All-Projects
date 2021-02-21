/*
** EPITECH PROJECT, 2019
** str is number
** File description:
** is this number
*/

int	my_str_isnum(char const *str)
{
    int	i = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            i = i + 1;
        else
            return (0);
    }
    return (1);
}
