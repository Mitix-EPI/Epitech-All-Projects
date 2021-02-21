/*
** EPITECH PROJECT, 2019
** za3ma
** File description:
** lola
*/

int    my_str_isupper(char const *str)
{
    int	i = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i = i + 1;
        else
            return (0);
    }
    return (1);
}
