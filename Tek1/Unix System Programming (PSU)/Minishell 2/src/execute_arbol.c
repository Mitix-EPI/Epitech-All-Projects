/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** execute_arbol
*/

#include "../include/my.h"

int execute_command(node_t *tmp, char **env, objt_struct_t **head)
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
    if (execute_executable(command, env) == 1)
        return (0);
    return (1);
}

void condition(char ***args, node_t *tmp, char ***envs, objt_struct_t **head)
{
    if (my_strcmp(tmp->value, "|") == 0) {
        execute_pipe(envs, tmp, head);
        return;
    }
    if (my_strcmp(tmp->value, ">") == 0) {
        execute_left_simple(args[1][0], tmp, envs, head);
        return;
    }
    if (my_strcmp(tmp->value, ">>") == 0) {
        execute_left_double(args[1][0], tmp, envs, head);
        return;
    }
    if (my_strcmp(tmp->value, "<") == 0) {
        execute_right_simple(args, envs, tmp, head);
        return;
    }
    if (my_strcmp(tmp->value, ";") == 0) {
        execute_dot_comma(tmp, envs, head);
        return;
    }
}

void leo_function(node_t *tmp, char **envi, char **env, objt_struct_t **head)
{
    char **args[] = {my_parse_commands(tmp->left->value, ' '),
    my_parse_commands(tmp->right->value, ' '), NULL};
    char **envs[] = {env, envi, NULL};

    condition(args, tmp, envs, head);
}

void maximilien(node_t *tmp, char **envi, char **env)
{
    char **command = my_parse_commands(tmp->value, ' ');
    char **envs[] = {env, envi, NULL};
    my_exec(command, envs, tmp);
}

void execute_arbol(node_t *tmp, char **envi, char **env, objt_struct_t **head)
{
    if (!tmp)
        return;
    char *tmp2 = symbol(tmp->value);
    if (tmp2 != NULL) {
        leo_function(tmp, envi, env, head);
        return;
    }
    if (execute_command(tmp, env, head) == 1)
        maximilien(tmp, envi, env);
    return;
}
