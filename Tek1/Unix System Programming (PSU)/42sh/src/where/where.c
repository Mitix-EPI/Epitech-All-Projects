/*
** EPITECH PROJECT, 2020
** where.c
** File description:
** where.c
*/

#include "where/where.h"
#include "where/where_following.h"

static int is_biltin(char *command)
{
    if ((strcmp(command, "alias") == 0) || (strcmp(command, "cd") == 0) \
    || (strcmp(command, "setenv") == 0) || (strcmp(command, "unsetenv") == 0) \
    || (strcmp(command, "which") == 0) || (strcmp(command, "where") == 0) \
    || (strcmp(command, "foreach") == 0) || (strcmp(command, "unalias") == 0) \
    || (strcmp(command, "time") == 0) || (strcmp(command, "if") == 0) \
    || (strcmp(command, "repeat") == 0) || (strcmp(command, "exit") == 0) \
    || (strcmp(command, "unset") == 0)) {
        printf("%s is a shell built-in\n", command);
        return (0);
    }
    return (1);
}

static int is_in_env(char *command, shell_t *shell)
{
    char **path = NULL;
    char *tmp = NULL;
    int found = 0;

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
            found = 1;
        }
    }
    return ((found == 1) ? 0 : 1);
}

static int is_alias(char *command, shell_t *shell)
{
    alias_t *cp = shell->alias;

    for (; cp; cp = cp->next) {
        if (strcmp(command, cp->name) == 0) {
            printf("%s is aliased to %s\n", command, cp->command);
            return (0);
        }
    }
    return (1);
}

static int where_following(shell_t *shell, char **command)
{
    int bol[3] = {0, 0, 0};
    int error = 0;

    for (int i = 0; command[i]; i++) {
        if (is_alias(command[i], shell) == 1)
            bol[0] = 1;
        if (is_biltin(command[i]) == 1)
            bol[1] = 1;
        if (is_in_env(command[i], shell) == 1)
            bol[2] = 1;
        if (bol[0] == 1 && bol[1] == 1 && bol[2] == 1)
            error = 1;
    }
    if (error == 1)
        return (1);
    return (0);
}

int where(shell_t *shell, char **command)
{
    if (command != NULL && command[0] == NULL) {
        printf("where: Too few arguments.\n");
        return (1);
    }
    if (shell->path == NULL) {
        printf("env: ‘where’: No such file or directory\n");
        return (1);
    }
    if (check_valid_command(command) == 1)
        return (1);
    if (where_following(shell, command) == 0)
        return (0);
    return (1);
}