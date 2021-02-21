/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** dot_comma
*/

#include "../include/my.h"

int execute_command3(node_t *tmp, char **envi, char **env, objt_struct_t **head)
{
    char **command = my_parse_commands(tmp->value, ' ');

    if (!command[0])
        return (0);
    if (my_strcmp(command[0], "unsetenv") == 0)
        return (my_unsetenv(command, head));
    if (my_strcmp(command[0], "cd") == 0)
        return (cd(command, head));
    if (my_strcmp(command[0], "env") == 0)
        return (my_env(head));
    if (my_strcmp(command[0], "setenv") == 0)
        return (my_setenv(command, head));
    return (my_fork(command, envi, env));
}

void execute_dot_comma(node_t *tmp, char ***envs, objt_struct_t **head)
{
    execute_arbol(tmp->left, envs[1], envs[0], head);
    execute_arbol(tmp->right, envs[1], envs[0], head);
}
