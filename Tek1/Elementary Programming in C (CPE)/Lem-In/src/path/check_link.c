/*
** EPITECH PROJECT, 2020
** check link
** File description:
** functions to check if link is good
*/

#include "lemin.h"

int check_not_equal(char **link_names)
{
    if (!link_names[0] || !link_names[1])
        return (0);
    return (1);
}

int get_comparison_start_end(char **links, paths_t *path, int len1, int len2)
{
    int nb = 0;

    if (my_strncmp(links[0], path->start, 0, len1))
        nb += 1;
    if (my_strncmp(links[0], path->end, 0, len1))
        nb += 1;
    if (my_strncmp(links[1], path->start, 0, len2))
        nb += 1;
    if (my_strncmp(links[1], path->end, 0, len2))
        nb += 1;
    return (nb);
}

int check_link_correspond(paths_t *path, char **link_names)
{
    int correspond = 0;
    int len1 = my_strlen(link_names[0]);
    int len2 = my_strlen(link_names[1]);
    char *str_test = NULL;

    for (int i = 0; path->nodes[i] != NULL; i += 1) {
        str_test = my_str(path->nodes[i]);
        if (my_strcmp(link_names[0], str_test))
            correspond += 1;
        if (my_strcmp(link_names[1], str_test))
            correspond += 1;
        free(str_test);
        if (correspond == 2)
            break;
    }
    correspond += get_comparison_start_end(link_names, path, len1, len2);
    return (correspond);
}

int check_the_link(paths_t *path, char *link)
{
    char **link_names = my_str_to_word_array('-', link);

    if (!check_not_equal(link_names)) {
        for (int i = 0; link_names[i] != NULL; i += 1)
            free(link_names[i]);
        free(link_names);
        return (0);
    }
    if (check_link_correspond(path, link_names) != 2) {
        for (int i = 0; link_names[i] != NULL; i += 1)
            free(link_names[i]);
        free(link_names);
        return (0);
    }
    return (1);
}
