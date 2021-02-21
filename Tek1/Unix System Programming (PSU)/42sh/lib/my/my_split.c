/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** String to word array by split
*/

#include <stdlib.h>
#include "my.h"

int    is_word(char c, char spl)
{
    if (c != spl)
        return (1);
    return (0);
}

int    get_nb_wd(char const *str, char spl)
{
    int nb_words = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (!is_word(str[index], spl))
            nb_words++;
    }
    return (nb_words + 1);
}

int    get_w_len(char const *str, int i, char spl)
{
    int len = 0;

    if (i == 1)
        i--;
    while (str[i] && is_word(str[i], spl)) {
        len++;
        i++;
    }
    return (len);
}

char  *get_w(char const *str, int i, char spl)
{
    int i_word = 0;
    char *word = malloc(sizeof(char) * (get_w_len(str, i, spl) + 1));

    if (i == 1)
        i--;
    while (str[i] && is_word(str[i], spl)) {
        word[i_word] = str[i];
        i++;
        i_word++;
    }
    word[i_word] = '\0';
    return (word);
}

char    **my_split(char const *str, char spl)
{
    int nb_words = get_nb_wd(str, spl);
    int i = 0;
    int i_a = 0;
    char **tab = malloc(sizeof(char *) * (nb_words + 1));
    for (; str[i] != '\0'; i++) {
        if ((!is_word(str[i], spl) || i == 0) && is_word(str[i + 1], spl)) {
            tab[i_a] = malloc(sizeof(char) * (get_w_len(str, i + 1, spl) + 1));
            tab[i_a] = get_w(str, i + 1, spl);
            tab[i_a][0] != '\0' ? i_a++ : 0;
        }
    }
    tab[i_a] = NULL;
    return (tab);
}
