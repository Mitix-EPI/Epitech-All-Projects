/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** IsLower
*/

int    my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            i++;
            continue;
        } else
            return (0);
        i++;
    }
    return (1);
}
