/*
** EPITECH PROJECT, 2020
** which.c
** File description:
** which.c
*/

#include "minishell2.h"
#include "which/which.h"

static int is_builtin(char *command)
{
    if ((strcmp(command, "alias") == 0) || (strcmp(command, "cd") == 0) \
    || (strcmp(command, "setenv") == 0) || (strcmp(command, "unsetenv") == 0) \
    || (strcmp(command, "which") == 0) || (strcmp(command, "where") == 0) \
    || (strcmp(command, "foreach") == 0) || (strcmp(command, "unalias") == 0) \
    || (strcmp(command, "time") == 0) || (strcmp(command, "if") == 0) \
    || (strcmp(command, "repeat") == 0) || (strcmp(command, "exit") == 0) \
    || (strcmp(command, "unset") == 0)) {
        printf("%s: shell built-in command.\n", command);
        return (0);
    }
    return (1);
}

static int is_in_env(char *command, shell_t *shell)
{
    char **path = NULL;
    char *tmp = NULL;

    if (access(command, X_OK) == 0) {
        printf("%s\n", command);
        return (0);
    }
    if (!shell->path || (strlen(shell->path) == 1 && shell->path[0] == '/'))
        return (1);
    path = my_split(shell->path, ':');
    for (int i = 0; path[i]; i++) {
        tmp = my_strcat2(path[i], "/", -1, 0);
        tmp = my_strcat2(tmp, command, -1, 0);
        if (access(tmp, X_OK) == 0) {
            printf("%s\n", tmp);
            return (0);
        }
    }
    return (1);
}

static int is_alias(char *command, shell_t *shell)
{
    alias_t *cp = shell->alias;

    for (; cp; cp = cp->next) {
        if (strcmp(command, cp->name) == 0) {
            printf("%s: \t aliased to %s\n", command, cp->command);
            return (0);
        }
    }
    return (1);
}

int which(shell_t *shell, char **command)
{
    int error = 0;

    if (command != NULL && command[0] == NULL) {
        printf("which: Too few arguments.\n");
        return (1);
    }
    for (int i = 0; command[i]; i++) {
        if (shell->path == NULL) {
            printf("which: no %s in ((null))\n", command[i]);
            error = 1;
            continue;
        }
        if (is_alias(command[i], shell) == 0)
            continue;
        if (is_builtin(command[i]) == 0 || (is_in_env(command[i], shell) == 0))
            continue;
        printf("%s: Command not found.\n", command[i]);
        error = 1;
    }
    return ((error == 1) ? 1 : 0);
}