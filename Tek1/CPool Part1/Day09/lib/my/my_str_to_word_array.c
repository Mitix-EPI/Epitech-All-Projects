/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** return value
*/

#include <stdlib.h>

int count_malloc(char const *cache)
{
    int i = 0;

    while (cache[i] != '\0') {
        i++;
    }
    i++;
    return (i);
}

char *my_get_str_word(char const *str, int *n, int char_max)
{
    int i = 0;
    char *cache;

    cache = malloc(sizeof(char) * char_max);
    while ((str[*n] >=48 && str[*n] <= 57) || (str[*n] >= 65 && str[*n] <= 90) || (str[*n] >= 97 && str[*n] <= 122)) {
        cache[i] = str[*n];
        i++;
        *n = *n + 1;
    }
    cache[i] = '\0';
    return (cache);
}

int my_nb_str(char const *str)
{
    int nb_str = 0;
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 122 || (str[i] > 57 && str[i] < 65)) {
            if ((str[i-1] >= 65 && str[i-1] <= 90) || (str[i-1] >= 48 && str[i-1] <= 57) || (str[i-1] >= 97 && str[i -1] <= 122) )
                nb_str++;
        }
        i++;
    }
    return (nb_str);
}

char **my_str_to_word_array(char const *str)
{
    char **str1;
    int nb_str = my_nb_str(str);
    int b = 0;
    int char_max = 0;
    int n = 0;
    int a = 0;
    int length = 0;

    length = count_malloc(str);
    nb_str++;
    for (int length = 0; str[length] != '\0'; length++) {
        if ((str[length] >= 65 && str[length] <= 90) || (str[length] >= 48 && str[length] <= 57) || (str[length] >= 97 && str[length] <= 122))
            b++;
        else if (str[length] > 122 || str[length] < 48) {
            if (b > char_max)
                char_max = b;
            b = 0;
        }
    }
    str1 = malloc(sizeof(char *) * nb_str + 1);
    for (int i = 0; i != nb_str; i++) {
        str1[i] = malloc(sizeof(char) * char_max + 1);
    }
    while (str[n] != '\0') {
        if (str[n] < 48 || str[n] > 122 || (str[n] > 57 && str[n] < 65)) {
            n++;
        }
        else {
            str1[a] = my_get_str_word(str, &n, char_max);
            a++;
        }
    }
    str1[a] = '\0';
    return (str1);
}
