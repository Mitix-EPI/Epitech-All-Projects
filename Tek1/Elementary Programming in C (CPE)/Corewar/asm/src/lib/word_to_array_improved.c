/*
** EPITECH PROJECT, 2020
** minishell1_improved
** File description:
** word_to_array_improved
*/

#include "asm.h"

int jump_nonalpha(char str, char autho[], char *inter_num[3])
{
    if (str == '\0')
        return (1);
    for (int i = 0; autho[i]; i += 1) {
        if (str == autho[i])
            return (0);
    }
    for (int i = 0; i < 3 && inter_num[i]; i += 1) {
        if (str >= inter_num[i][0] && str <= inter_num[i][1])
            return (0);
    }
    return (1);
}

int biglen(char *str, char autho[], char *inter_num[3])
{
    int i = 0;
    int size = 0;

    while (str[i]) {
        if (jump_nonalpha(str[i], autho, inter_num) == 0 && i == 0)
            size += 1;
        if ((i > 0) && jump_nonalpha(str[i], autho, inter_num) == 0
            && (jump_nonalpha(str[i - 1], autho, inter_num) == 1))
            size += 1;
        i += 1;
    }
    return (size);
}

int my_len(char *str, int i, char autho[], char *inter_num[3])
{
    int j = 0;
    int k = i;

    while (jump_nonalpha(str[k], autho, inter_num) == 0) {
        j++;
        k++;
    }
    return (j);
}

char *convert(char *src, int *i, char autho[], char *inter_num[3])
{
    int j = 0;
    char *ret = malloc(sizeof(char) * (my_len(src, *i, autho, inter_num) + 1));

    while (jump_nonalpha(src[*i], autho, inter_num) == 0) {
        ret[j] = src[*i];
        *i += 1;
        j += 1;
    }
    ret[j] = '\0';
    return (ret);
}

char **word_array(char *str, char autho[], char *inter_num[3])
{
    char **tab = NULL;
    int size = biglen(str, autho, inter_num);
    int len = 0;
    int i = 0;
    int m = my_strlen(str);

    if (!str)
        return (NULL);
    tab = malloc(sizeof(char *) * (size + 1));
    for (int k = 0; k < m; k += 1) {
        if (jump_nonalpha(str[k], autho, inter_num) == 0) {
            tab[i] = convert(str, &k, autho, inter_num);
            i += 1;
        }
    }
    tab[size] = NULL;
    return (tab);
}