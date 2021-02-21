/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** return value
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] != 45 && str[i] < 48 || str[i] > 57 ) {
            return (0);
        }
        i++;
    }
    return (1);
}
