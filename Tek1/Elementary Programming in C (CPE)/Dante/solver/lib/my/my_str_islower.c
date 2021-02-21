/*
** EPITECH PROJECT, 2019
** is this lower
** File description:
** this is lower
*/

int    my_str_islower(char const *str)
{
    int	i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            i = i + 1;
        else
            return (0);
    }
    return (1);
}
