/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_str_to_word_array.c
*/

#include "../my_tower.h"

int    nb_word(char *str)
{
    int compteur = 0;

    for (int a = 0; str[a] != '\0'; a = a + 1) {
        if (str[a] == '\n')
            compteur++;
    }
    return (compteur);
}

int    is_alpha(char c)
{
    return ((c != '\n') && (c != '\0'));
}

char    **fill_tab(char **tab, char *str, int t)
{
    int i = 0;
    int e = 0;
    int x;

    for (int c = 0; c < t ; c++) {
        x = 0;
        if (!is_alpha(str[e])) {
            e += 1;
            i += 1;
        }
        for (; is_alpha(str[e]); e += 1);
        tab[c] = malloc(sizeof(char) * (e - i + 1));
        for (; i < e; i += 1) {
            tab[c][x] = str[i];
            x += 1;
        }
        tab[c][x] = '\0';
    }
    return tab;
}

char **my_str_to_word_array(char *str)
{
    char **tab;
    int t = nb_word(str);

    tab = malloc(sizeof(char *) * (t + 1));
    tab[t] = NULL;
    if (str[0] == '\0')
        return (NULL);
    return (fill_tab(tab, str, t));
}