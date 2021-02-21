/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** IsNum
*/

int    my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '-') {
            i++;
            continue;
        } else
            return (0);
        i++;
    }
    return (1);
}