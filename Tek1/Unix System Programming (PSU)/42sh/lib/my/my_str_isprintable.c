/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** isPrintable
*/

int    my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 127 || str[i] < 32)
            return (0);
        i++;
    }
    return (1);
}
