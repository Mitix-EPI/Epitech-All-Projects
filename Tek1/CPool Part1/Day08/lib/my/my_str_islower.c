/*
** EPITECH PROJECT, 2019
** my_str_islower.c
** File description:
** return value
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 97 || str[i] > 122)
            return (0);
        i++;
    }
    return (1);
}
