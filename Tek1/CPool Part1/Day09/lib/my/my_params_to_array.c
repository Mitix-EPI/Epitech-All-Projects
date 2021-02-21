/*
** EPITECH PROJECT, 2019
** my_params_to_array.c
** File description:
** structure
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *params;

    params = malloc(sizeof(struct info_param));
    while (i < ac) {
        if (params == NULL)
            return (NULL);
        params[i].length = my_strlen(av[i]);
        params[i].str = av[i];
        params[i].copy = my_strdup(av[i]);
        params[i].word_array = my_str_to_word_array(av[i]);
        i++;
    }
    return (params);
}
