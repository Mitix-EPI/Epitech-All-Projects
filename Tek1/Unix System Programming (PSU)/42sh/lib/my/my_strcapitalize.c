/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** strcapitalize
*/

int    my_char_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int    my_char_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

char	*my_strcapitalize(char *str)
{
    int i = -1;
    int next_w = 1;

    while (str[(i = i + 1)] != '\0') {
        if (str[i] < 123 && str[i] > 96 && next_w == 1) {
            next_w = 0;
            str[i] -= 32;
        }
    if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
        next_w = 1;
    }
    return (str);
}
