/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** String to word array
*/

#include <stdlib.h>
#include "my.h"

int    is_alpha(char c)
{
    if (c == '\n' || c == '\t' || c == ' ')
        return (0);
    return (1);
}

int    get_nb_words(char const *str)
{
    int nb_words = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (!is_alpha(str[index]))
            nb_words++;
    }
    return (nb_words + 1);
}

int    get_len_word(char const *str, int i)
{
    int len = 0;

    if (i == 1 && is_alpha(str[0]))
        i--;
    while (is_alpha(str[i])) {
        len++;
        i++;
    }
    return (len);
}

char  *get_word(char const *str, int i)
{
    int i_word = 0;
    char *word = malloc(sizeof(char) * (get_len_word(str, i) + 1));

    if (i == 1 && is_alpha(str[0]))
        i--;
    while (is_alpha(str[i])) {
        word[i_word] = str[i];
        i++;
        i_word++;
    }
    word[i_word] = '\0';
    return (word);
}

char    **my_str_to_word_array(char *str)
{
    int nb_words = 0;
    int i = 0;
    int i_a = 0;
    char **tab = NULL;

    if (is_alpha(str[my_strlen(str) - 1]))
        str = my_strcat2(str, "\n", -1, 0);
    nb_words = get_nb_words(str);
    tab = malloc(sizeof(char *) * (nb_words + 1));
    for (; str[i + 1] != '\0'; i++) {
        if ((!is_alpha(str[i]) || i == 0) && is_alpha(str[i + 1])) {
            tab[i_a] = malloc(sizeof(char) * (get_len_word(str, i + 1) + 1));
            tab[i_a] = get_word(str, i + 1);
            tab[i_a][0] != '\0' ? i_a++ : 0;
        }
    }
    tab[i_a] = NULL;
    return (tab);
}
