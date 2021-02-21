/*
** EPITECH PROJECT, 2019
** my_str_isuppper
** File description:
** IsUpper
*/

int    my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            i++;
            continue;
        } else
            return (0);
        i++;
    }
    return (1);
}
