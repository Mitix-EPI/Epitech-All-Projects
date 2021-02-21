/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job_list
*/

#include "jobs/job_list.h"

job_t *get_head(void)
{
    static job_t head = NULL;

    return (&head);
}

char *get_string(char **argv)
{
    char *str = NULL;

    if (argv == NULL)
        return (NULL);
    for (int i = 0; argv[i]; i += 1) {
        str = my_strcat2(str, argv[i], -1, 0);
        if (argv[i + 1])
            str = my_strcat2(str, " ", -1, 0);
    }
    return (str);
}

job_t prepare_node(pid_t process, int *turn, char *line)
{
    job_t *head = get_head();
    job_t obj = *head;
    job_t node = malloc(sizeof(job_node_t));

    node->next = NULL;
    node->pid = process;
    node->pos = *turn + 1;
    node->is_done = 0;
    node->line = line;
    if (!obj) {
        node->prev = NULL;
        *head = node;
        *turn += 1;
        my_printf("[%d] %d\n", node->pos, process);
        return (NULL);
    }
    return (node);
}

void add_node(pid_t process, int *turn, char **argv)
{
    job_t *head = get_head();
    job_t obj = *head;
    job_t node = prepare_node(process, turn, get_string(argv));

    if (!node)
        return;
    while (obj->next) {
        if (obj->is_done == 1) {
            obj->pid = process;
            obj->line = node->line;
            obj->is_done = 0;
            my_printf("[%d] %d\n", obj->pos, process);
            return;
        }
        obj = obj->next;
    }
    *turn += 1;
    node->prev = obj;
    obj->next = node;
    my_printf("[%d] %d\n", node->pos, process);
}