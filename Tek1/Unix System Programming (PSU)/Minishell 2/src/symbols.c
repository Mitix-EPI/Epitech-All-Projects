/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** symbols
*/

#include "../include/my.h"

int my_count_sym(char *str)
{
    int i = 0;
    int len = 0;
    for (; str && str[i]; i++)
        if (str[i] != ' ' || str[i] != 9)
            len++;
    return (len);
}

char *symbol_part2(char *str, char **sym, int a, int i)
{
    int len = my_count(sym[a]);
    int j = len - 1;
    if (str[i] == sym[a][j]) {
        if (len == 1 && ((!str[i - 1] || !str[i + 1]) || (str[i - 1] !=
        sym[a][j] && str[i + 1] != sym[a][j]))) {
            return (sym[a]);
        }
        else if (len == 2 && str[i - 1] == sym[a][j - 1]) {
            return (sym[a]);
        }
        return (NULL);
    }
    return (NULL);
}

char *symbol(char *str)
{
    char *sym[] = {";", ">", ">>", "<", "<<", "|", NULL};
    char *tmp = NULL;

    for (int a = 0; sym[a] != NULL; a++) {
        for (int i = my_count(str) - 1; i >= 0; i--) {
            tmp = symbol_part2(str, sym, a, i);
            if (tmp != NULL) {
                return (tmp);
            }
        }
    }
    return (NULL);
}

int serch2_symb(char *str, char *sym, int *count, int *ij)
{
    if (str[ij[0]] == sym[ij[1]]) {
        *count += 1;
        if (*count == my_count_sym(sym))
            return (ij[0]);
    } else
        *count = 0;
    return (-84);
}

int search_symb(char *str, char *sym)
{
    int count = 0;
    int ij[2] = {0};

    for (int i = my_count(str) - 1; i >= 0; i--, count = 0)
        for (int j = 0; sym && sym[j]; j++) {
            ij[0] = i;
            ij[1] = j;
            if (serch2_symb(str, sym, &count, ij) != -84)
                return (i);
        }
    return (0);
}