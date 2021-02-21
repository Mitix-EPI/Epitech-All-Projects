/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Cat two strings
*/

int my_strlen(char *str);

char    *my_strncat(char *dest, char const *src, int nb)
{
    int dest_size = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[dest_size + i] = src[i];
    dest[dest_size + i] = '\0';
    return (dest);
}
