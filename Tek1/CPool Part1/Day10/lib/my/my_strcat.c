/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** return value
*/

int my_count_str(char const *dest)
{
    int i = 0;

    while (dest[i] != '\0'){
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int nb_dest = my_count_str(dest);
    int nb_src = my_count_str(src);
    int i = 0;

    while (nb_src >= i){
        dest[nb_dest] = src[i];
        i++;
        nb_dest++;
    }
    return (dest);
}
