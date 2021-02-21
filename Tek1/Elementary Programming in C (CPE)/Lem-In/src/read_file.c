/*
** EPITECH PROJECT, 2020
** read file
** File description:
** function for parsing and reading
*/

#include "lemin.h"

void set_start_end_str(paths_t *path, int type)
{
    char *content = NULL;
    size_t len = 0;
    int ret = 0;

    if ((ret = getline(&content, &len, stdin)) != -1)
        cutstr(content);
    if (!check_my_node(content))
        return;
    if (type == 0) {
        path->start = (count_numbers(content, 0) == 2) ? content : "\0";
        path->debug = realloc_array(path->debug, "##start");
        path->debug = realloc_array(path->debug, path->start);
    } else if (type == 1) {
        path->end = (count_numbers(content, 0) == 2) ? content : "\0";
        path->debug = realloc_array(path->debug, "##end");
        path->debug = realloc_array(path->debug, path->end);
    }
}

int set_node_or_link(char *content, paths_t *path, int type)
{
    static int tunnels = 0;

    cutstr(content);
    if (type == 0) {
        if (!check_my_node(content))
            return (0);
        path->nodes = realloc_array(path->nodes, content);
        path->debug = realloc_array(path->debug, content);
        path->nb_rooms += 1;
    } else if (type == 1) {
        if (!check_the_link(path, content))
            return (0);
        if (tunnels == 0) {
            tunnels = 1;
            path->debug = realloc_array(path->debug, "#tunnels");
        }
        path->links = realloc_array(path->links, content);
        path->debug = realloc_array(path->debug, content);
    }
    return (1);
}

void parse_paths(paths_t *path)
{
    char *content = NULL;
    size_t len = 0;
    int ret = 0;

    while ((ret = getline(&content, &len, stdin)) != -1) {
        if (check_ant_nb(content, path))
            continue;
        ret = check_start_end_str(content, path);
        if (ret == -1)
            break;
        if (ret != 1)
            ret = set_node_or_link(content, path, what_line(content));
        if (ret == 0) {
            path->ants_number = 0;
            break;
        }
    }
    check_name_node(path);
    free(content);
}

paths_t *read_file(void)
{
    paths_t *paths = malloc(sizeof(*paths));

    init_path(paths);
    parse_paths(paths);
    if (!handling_path(paths))
        return (NULL);
    return (paths);
}
