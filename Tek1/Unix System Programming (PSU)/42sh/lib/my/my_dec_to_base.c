/*
** EPITECH PROJECT, 2019
** my_charcat
** File description:
** Cat char
*/

#include "my.h"

char *infin_mod(char *, char *);
char *infin_div(char *, char *);

static int    get_pos_base(char c, char const *b)
{
    for (int i = 0; b[i]; i++)
        if (b[i] == c)
            return (i);
}

char    *my_dec_to_base(char *str, char *b)
{
    char *result_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *result_mod = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *result_div = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *left_nb = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *base_len = malloc(sizeof(char) * my_strlen(b) + 1);

    base_len = my_itoa(my_strlen(b));
    left_nb = my_strdup(str);
    while (left_nb && left_nb[0] != '0') {
        result_mod = infin_mod(left_nb, base_len);
        result_div = infin_div(left_nb, base_len);
        result_str = my_strcat(result_str, result_div);
        left_nb = result_mod;
    }
    return (my_revstr(result_str));
}