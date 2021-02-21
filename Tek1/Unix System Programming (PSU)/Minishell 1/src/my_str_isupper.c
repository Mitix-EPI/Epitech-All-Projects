/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_isupper
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
