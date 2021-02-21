/*
** EPITECH PROJECT, 2020
** main_lemin
** File description:
** main_lemin
*/

#include "lemin.h"

static int count_nb_nodes(char **map)
{
    int nb_nodes = 2;

    for (int i = 0; map[i] != NULL; i++, nb_nodes++);
    return (nb_nodes);
}

node_t **create_all_nodes(paths_t *path)
{
    const int len = count_nb_nodes(path->nodes);
    node_t **nodes = malloc(sizeof(nodes) * (len + 1));
    char *str = NULL;

    nodes[len] = NULL;
    str = my_str(path->start);
    nodes[0] = new_node(str);
    free(str);
    str = my_str(path->end);
    nodes[1] = new_node(str);
    free(str);
    for (int i = 2; i < len; i++) {
        str = my_str(path->nodes[i - 2]);
        nodes[i] = new_node(str);
        free(str);
    }
    return (nodes);
}

char *get_second_id(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    new[len] = '\0';
    for (; str && str[i] && str[i] != '-'; ++i);
    if (str[i + 1])
        i += 1;
    for (; str[i]; i++, j++)
        new[j] = str[i];
    for (;j <= my_strlen(str); j++)
        new[j] = 0;
    return (new);
}

int main_lemin(void)
{
    paths_t *path = read_file();
    node_t **nodes = NULL;

    if (!path)
        return (84);
    nodes = create_all_nodes(path);
    link_all_nodes(path, nodes);
    if (check_if_possible(path, nodes[0]) == 0)
        return (84);
    display_debug(path);
    algorithm(nodes, path);
    free_path(path);
    free_nodes(nodes);
    return (0);
}
