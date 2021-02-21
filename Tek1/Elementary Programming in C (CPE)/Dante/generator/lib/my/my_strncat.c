/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** copy n paste
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int n = 0;
    while (dest[i] != '\0')
        i++;
    while (src[n] != src[nb] && src[n] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return (dest);
}
