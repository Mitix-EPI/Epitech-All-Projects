/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** return value
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 90 || str[i] < 65)
            return (0);
        i++;
    }
    return (1);
}
