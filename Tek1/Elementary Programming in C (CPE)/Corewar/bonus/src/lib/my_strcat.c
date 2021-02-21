/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcat(char *s1, char *s2)
{
    int len = my_strlen(s1) + my_strlen(s2);
    char *ret = malloc(sizeof(s1) * (len + 1));
    int i = 0;

    for (; s1[i]; i += 1)
        ret[i] = s1[i];
    for (int j = 0; s2[j]; j += 1, i += 1)
        ret[i] = s2[j];
    ret[i] = '\0';
    return (ret);
}
