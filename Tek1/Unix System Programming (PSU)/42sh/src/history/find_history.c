/*
** EPITECH PROJECT, 2020
** find_history.c
** File description:
** find_history.c
*/

#include "minishell2.h"
#include "history/find_history.h"

char *check_command(char *command, history_t *cp, int i)
{
    for (int j = 0; command[j]; j++) {
        if (cp->command[i] == command[j]) {
            return (cp->command);
        }
    }
    return (NULL);
}

char *look_command(history_t *cp, char *command)
{
    int i = 0;
    char *cmd = NULL;

    for (i = 0; cp->command[i]; i++) {
        cmd = check_command(command, cp, i);
        if (cmd != NULL)
            return (cmd);
    }
    return (NULL);
}

char *find_history(char *command, history_t **node)
{
    history_t *cp = *node;
    char *cmd = NULL;
    int bol = 0;

    for (; cp; cp = cp->next) {
        cmd = look_command(cp, command);
        if (cmd != NULL)
            return (cmd);
    }
    return (NULL);
}