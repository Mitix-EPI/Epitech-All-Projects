/*
** EPITECH PROJECT, 2019
** str_copy
** File description:
** j'ai encore mon visa
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
