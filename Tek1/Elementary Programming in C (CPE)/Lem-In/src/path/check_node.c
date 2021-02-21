/*
** EPITECH PROJECT, 2020
** check node
** File description:
** functions to check the node
*/

#include "lemin.h"

int my_str_num(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int count_numb_array(char **content)
{
    int nb = 0;

    for (; content[nb] != NULL; nb += 1);
    return (nb);
}

int check_my_node(char *content)
{
    char **my_content = my_str_to_word_array(' ', content);

    if (count_numb_array(my_content) != 3)
        return (0);
    if (!my_content[0] || !my_content[1] || !my_content[2]) {
        for (int i = 0; my_content[i] != NULL; i += 1)
            free(my_content[i]);
        free(my_content);
        return (0);
    }
    if (!my_str_num(my_content[1]) || !my_str_num(my_content[2])) {
        for (int i = 0; my_content[i] != NULL; i += 1)
            free(my_content[i]);
        free(my_content);
        return (0);
    }
    for (int i = 0; my_content[i] != NULL; i += 1)
        free(my_content[i]);
    free(my_content);
    return (1);
}