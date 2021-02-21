/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** Return 1 is string is alphabetic
*/

int    my_str_isalpha(char const *str)
{
    int i = 0;
    char c;

    while (str[i] != '\0') {
        c = str[i];
        if (c >= 'a' && c <= 'z') {
            i++;
            continue;
        } else if (c >= 'A' && c <= 'Z') {
            i++;
            continue;
        } else
            return (0);
    }
    return (1);
}
