/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** copies string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}
