/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** return value
*/

int my_count_str1(char const *dest)
{
    int i = 0;

    while (dest[i] != '\0'){
        i++;
    }
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int nb_dest = my_count_str1(dest);
    int nb_src = my_count_str1(src);
    int i = 0;

    while (i < nb && nb_src >= i){
        dest[nb_dest] = src[i];
        i++;
        nb_dest++;
    }
    return (dest);
}
