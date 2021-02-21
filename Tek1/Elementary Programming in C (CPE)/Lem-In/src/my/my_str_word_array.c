/*
** EPITECH PROJECT, 2020
** my str word array
** File description:
** function to make an array of str
*/

#include "lemin.h"

int jump_index(int index, char *str, char split)
{
    for (; str[index] && str[index] == split; index += 1);
    return (index);
}

int count_words_array(char *str, char split)
{
    int nb = 0;
    int index = jump_index(0, str, split);

    for (; str[index]; index += 1)
        if (str[index] == split) {
            nb += 1;
            index = jump_index(index, str, split) - 1;
        }
    return (nb);
}

int my_strlen_array(char *str, int index, char split)
{
    int len = 0;

    for (; str[index]; index += 1) {
        if (str[index] == split)
            return (len);
        len += 1;
    }
    return (len);
}

char **my_str_to_word_array(char split, char *str)
{
    int index = jump_index(0, str, split);
    int len = count_words_array(str, split);
    int tab_index = -1;
    int str_index = 0;
    char **array = malloc(sizeof(char *) * (len + 2));

    array[len + 1] = NULL;
    for (; str[index]; index += 1) {
        if (str[index] == split || index == jump_index(0, str, split)) {
            index = jump_index(index, str, split);
            tab_index += 1;
            str_index = 0;
            len = my_strlen_array(str, index, split);
            array[tab_index] = malloc(sizeof(char) * (len + 1));
            array[tab_index][len] = '\0';
        }
        array[tab_index][str_index] = str[index];
        str_index += 1;
    }
    return (array);
}