/*
** EPITECH PROJECT, 2020
** check special rooms
** File description:
** functions to check start and end rooms
*/

#include "lemin.h"

int check_ant_nb(char *content, paths_t *path)
{
    int spaces = 0;

    if (path->ants_number > 0 || content[0] == '#')
        return (0);
    cutstr(content);
    spaces = count_numbers(content, 0);
    if (spaces == 0) {
        path->ants_number = my_atoi(content);
        path->debug = realloc_array(path->debug, "#number_of_ants");
        path->debug = realloc_array(path->debug, content);
        path->debug = realloc_array(path->debug, "#rooms");
        return (1);
    }
    return (1);
}

int check_start_end_str(char *content, paths_t *path)
{
    if (my_strncmp(content, "##start", 0, 7)) {
        if (path->start) {
            free(path->start);
            path->start = NULL;
            return (-1);
        }
        set_start_end_str(path, 0);
        return (1);
    } else if (my_strncmp(content, "##end", 0, 5)) {
        if (path->end) {
            free(path->end);
            path->end = NULL;
            return (-1);
        }
        set_start_end_str(path, 1);
        return (1);
    }
    return (0);
}