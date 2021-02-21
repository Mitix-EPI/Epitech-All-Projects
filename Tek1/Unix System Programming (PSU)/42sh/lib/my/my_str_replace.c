/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my.h
*/

#include "my.h"

char *my_str_replace(const char *str, const char *old, const char *new)
{
    char *ret = NULL;
    int i = 0;
    int index = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], old) == &str[i]) {
            index++;
            i += strlen(old) - 1;
        }
    }
    ret = malloc(sizeof(char) * (i + index * (strlen(new) - strlen(old)) + 1));
    i = 0;
    while (*str)
        if (strstr(str, old) == str) {
            strcpy(&ret[i], new);
            i += strlen(new);
            str += strlen(old);
        } else
            ret[i++] = *str++;
    ret[i] = '\0';
    return (ret);
}