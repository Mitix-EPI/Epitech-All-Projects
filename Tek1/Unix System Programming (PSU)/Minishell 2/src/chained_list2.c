/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** chained_list2
*/

#include "../include/my.h"

objt_struct_t *add_node_at_the_end(char *name, char *txt, objt_struct_t *strct)
{
    objt_struct_t *head = malloc(sizeof(*head));
    objt_struct_t *tmp = strct;

    head->name = name;
    head->txt = txt;
    head->next = NULL;


    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

objt_struct_t *set_nodes(objt_struct_t *head, char **env)
{
    char *tmp = NULL;
    int k = 0;

    for (int i = 0; env[i] != NULL; i++) {
        k = 0;
        tmp = get_name(env[i], &k);
        char *str = &env[i][k + 1];
        head = add_node_at_the_end(tmp, str, head);
    }
    return (head);
}