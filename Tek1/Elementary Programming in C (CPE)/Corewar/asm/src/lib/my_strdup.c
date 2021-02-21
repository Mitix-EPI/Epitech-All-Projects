/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strdup
*/

#include "asm.h"
#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *str)
{
    char *tmp = NULL;
    int len = 0;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    tmp = malloc(sizeof(char) * (len + 2));
    fill_str(tmp, len + 1, '\0');
    for (int i = 0; str && str[i]; i++)
        tmp[i] = str[i];
    return (tmp);
}
