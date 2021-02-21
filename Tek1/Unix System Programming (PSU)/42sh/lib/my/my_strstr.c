/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Reproduce strstr
*/

int my_strlen(char const *);

char    *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int nb = my_strlen(to_find);
    int b;

    while (str[i] != '\0') {
        b = 0;
        while (to_find[b] == str[i+b] && to_find[b] != '\0') {
            b++;
        }
        if (b == nb)
            return (str + i);
        i++;
    }
    return ((void *)0);
}
