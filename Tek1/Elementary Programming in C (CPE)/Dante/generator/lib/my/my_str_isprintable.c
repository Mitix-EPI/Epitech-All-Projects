/*
** EPITECH PROJECT, 2019
** is this printable
** File description:
** this is printable
*/

int    my_str_isprintable(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] == 127)
            i += 1;
        else
            return (0);
    }
    return (1);
}
