/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse a string
*/

char *my_strdup(char const *);

char    *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char temp;
    char *final_str = my_strdup(str);

    while (final_str[j] != '\0')
        j++;
    while (i < j / 2) {
        temp = final_str[i];
        final_str[i] = final_str[j - 1 - i];
        final_str[j - i - 1] = temp;
        i++;
    }
    return (final_str);
}
