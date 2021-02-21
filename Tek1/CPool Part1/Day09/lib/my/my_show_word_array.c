/*
** EPITECH PROJECT, 2019
** my_show_word_array.c
** File description:
** return value
*/

#include <stdlib.h>
#include <unistd.h>

void print_str_show_word(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

int count_my_all_charac_2(char * const *tab)
{
    int i = 0;
    int j = 0;
    int res;

    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            j++;
            res++;
        }
        i++;
    }
    res = res + i;
    return (res);
}

int my_show_word_array(char * const *tab)
{
    int i = 0;
    int j = 0;
    int u = 0;
    char *str;

    str = malloc(sizeof(char) * (count_my_all_charac_2(tab)));
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            str[u] = tab[i][j];
            j++;
            u++;
        }
        str[u] = '\n';
        u++;
        i++;
    }
    str[u] = '\0';
    print_str_show_word(str);
    return (0);
}
