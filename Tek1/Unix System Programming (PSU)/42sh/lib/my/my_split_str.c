/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** split
*/

#include "my.h"

char    **my_split_str(char *str, char *del)
{
    char **tab = NULL;
    char *ptr = strtok(str, del);
    int i = 0;

    while (ptr != NULL) {
        tab = realloc(tab, sizeof(char *) * (i + 1));
        tab[i] = strdup(ptr);
        i++;
        ptr = strtok(NULL, del);
    }
    tab = realloc(tab, sizeof(char *) * (i + 1));
    tab[i] = NULL;
    return (tab);
}