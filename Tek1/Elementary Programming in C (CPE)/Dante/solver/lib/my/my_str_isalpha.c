/*
** EPITECH PROJECT, 2019
** is this alpha
** File description:
** this is alpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
            i += 1;
        else
            return (0);
    }
    return (1);
}
