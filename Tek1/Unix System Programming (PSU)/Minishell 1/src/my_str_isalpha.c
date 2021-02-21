/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_isalpha
*/

int my_str_isalpha1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
        (str[i] > 90 && str[i] < 97) || str[i] > 122)
        && str[i] != '_' && str[i] != '=') {
            return (0);
        }
        i++;
    }
    return (1);
}

int my_str_isalpha2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)) {
            return (0);
        }
        i++;
    }
    return (1);
}
