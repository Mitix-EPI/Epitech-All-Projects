/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n char
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int nb = 0;
    for (int i = 0; i != n; i++) {
        nb++;
        dest[i] = src[i];
    }
    dest [nb] = '\0';
    return (dest);
}
