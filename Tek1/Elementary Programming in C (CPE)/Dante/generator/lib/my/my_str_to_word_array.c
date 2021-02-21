/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

int is_alpha_num(char c, char separator)
{
    if (separator == 0)
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'));
    else {
        if (c == separator)
            return 0;
        return 1;
    }
}

int arg_num(char const *str, char separator)
{
    int arg = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((is_alpha_num(str[i], separator) && i == 0) ||
        (i > 0 && is_alpha_num(str[i], separator)
        && !is_alpha_num(str[i - 1], separator)))
            arg += 1;
    }
    return (arg);
}

void my_creater(char **array, char const *str, int nb, char separator)
{
    int len = 0;
    int i = 0;

    while (!is_alpha_num(str[i], separator) && str[i] != '\0')
        i += 1;
    for (int j = 0; j < nb; j += 1) {
        len = 0;
        while (is_alpha_num(str[i], separator) && str[i] != '\0') {
            len += 1;
            i += 1;
        }
        array[j] = malloc(sizeof(char) * (len + 1));
        while (!is_alpha_num(str[i], separator) && str[i] != '\0')
            i += 1;
    }
}

char **my_filler(char **array, char const *str, int nb, char separator)
{
    int len = 0;
    int i = 0;

    while (!is_alpha_num(str[i], separator) && str[i] != '\0')
        i += 1;
    for (int j = 0; j < nb; j += 1) {
        len = 0;
        while (is_alpha_num(str[i], separator) && str[i] != '\0') {
            array[j][len] = str[i];
            len += 1;
            i += 1;
        }
        array[j][len] = 0;
        while (!is_alpha_num(str[i], separator) && str[i] != '\0')
            i += 1;
    }
    return (array);
}

char **my_str_to_word_array(char const *str, char separator)
{
    int nb = arg_num(str, separator);
    char **array = malloc(sizeof(char *) * (nb + 1));

    array[nb] = NULL;
    my_creater(array, str, nb, separator);
    return (my_filler(array, str, nb, separator));
}