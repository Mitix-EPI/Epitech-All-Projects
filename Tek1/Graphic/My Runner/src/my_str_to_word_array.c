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

    cache = malloc(sizeof(char) * char_max + 1);
    while ((str[*n] >= 48 && str[*n] <= 57) || (str[*n] >= 65 &&
        str[*n] <= 90) || (str[*n] >= 97 && str[*n] <= 122) ||
        str[*n] == 32 || str[*n] == 35) {
        cache[i] = str[*n];
        cache[i + 1] = '\0';
        i++;
        *n = *n + 1;
    }
    return (cache);
}

int my_nb_str(char const *str)
{
    int nb_str = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            nb_str++;
    }
    return (nb_str);
}

int set_char_max(char const *str, int length)
{
    int char_max = 0;
    int b = 0;

    for (length = 0; str[length] != '\0'; length++) {
        if ((str[length] >= 65 && str[length] <= 90) || (str[length] >= 48 &&
            str[length] <= 57) || (str[length] >= 97 && str[length] <= 122) ||
            str[length] == 32 || str[length] == 35)
            b++;
        else if (str[length] > 122 || (str[length] < 48 &&
            str[length != 32] && str[length] != 35)) {
            if (b > char_max)
                char_max = b;
            b = 0;
        }
    }
    return (char_max);
}

char **my_str_to_word_array(char const *str)
{
    char **str1;
    int nb_str = my_nb_str(str) + 1;
    int length = count_malloc(str);
    int char_max = set_char_max(str, length);
    int n = 0;
    int a = 0;

    str1 = malloc(sizeof(char *) * (nb_str + 1));
    str1[nb_str] = NULL;
    for (int i = 0; i != nb_str; i++)
        str1[i] = malloc(sizeof(char) * char_max + 1);
    while (str[n] != '\0') {
        if ((str[n] != 32 && str[n] != 35 && str[n] < 48) ||
        str[n] > 122 || (str[n] > 57 && str[n] < 65))
            n += 1;
        else
            (str1[a++] = my_get_str_word(str, &n, char_max));
    }
    return (str1);
}