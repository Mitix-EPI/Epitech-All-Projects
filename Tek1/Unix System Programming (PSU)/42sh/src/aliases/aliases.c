/*
** EPITECH PROJECT, 2020
** aliases.c
** File description:
** aliases.c
*/

#include "minishell2.h"
#include "aliases/aliases.h"

int update_alias(char *command, char *name, alias_t **node)
{
    alias_t *tmp = *node;

    while (tmp) {
        if (!strcmp(tmp->name, name)) {
            tmp->command = my_strdup(command);
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void add_alias(char *command, char *name, alias_t **node)
{
    alias_t *new = malloc(sizeof(alias_t));
    alias_t *tmp = *node;

    if (update_alias(command, name, node))
        return;
    new->command = my_strdup(command);
    new->name = my_strdup(name);
    new->next = NULL;
    if (*node == NULL) {
        new->previous = NULL;
        *node = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->previous = tmp;
}

void unset_alias(shell_t *shell, char *name)
{
    alias_t *tmp = shell->alias;

    while (tmp) {
        if (strcmp(tmp->name, name)) {
            tmp = tmp->next;
            continue;
        }
        if (!strcmp(tmp->name, shell->alias->name)) {
            shell->alias = shell->alias->next ? shell->alias->next : NULL;
            shell->alias ? shell->alias->previous = NULL : 0;
            return;
        }
        tmp->previous->next = tmp->next;
        if (tmp->next)
            tmp->next->previous = tmp->previous;
        return;
    }
}

char *get_alias_cmd(shell_t *shell, char *name, char *alias_hist, int *loop)
{
    alias_t *tmp = shell->alias;

    while (tmp) {
        if (my_strcmp(tmp->name, name)) {
            tmp = tmp->next;
            continue;
        }
        if (my_arr_contain(my_split_str(alias_hist, ";"), tmp->command)) {
            *loop = 1;
            return (NULL);
        }
        alias_hist = my_strcat2(alias_hist, ";", -1, 0);
        alias_hist = my_strcat2(alias_hist, tmp->name, -1, 0);
        if (!strcmp(name, tmp->command))
            return (tmp->command);
        if (!get_alias_cmd(shell, tmp->command, alias_hist, loop))
            return (tmp->command);
        else
            return (get_alias_cmd(shell, tmp->command, alias_hist, loop));
    }
    return (NULL);
}

char *proceed_alias(shell_t *shell, char *command)
{
    char **arr_command = NULL;
    char *result = NULL;
    char *alias_history = malloc(sizeof(char));
    int alias_loop = 0;

    if (!command || command[0] == '\0')
        return (command);
    arr_command = my_split_str(my_strdup(command), " \t\n");
    alias_history[0] = '\0';
    result = get_alias_cmd(shell, arr_command[0], alias_history, &alias_loop);
    if (alias_loop) {
        printf("Alias loop.\n");
        return ("");
    }
    if (!result)
        return (command);
    arr_command[0] = result;
    command = my_arr_join(arr_command, " ");
    return (command);
}