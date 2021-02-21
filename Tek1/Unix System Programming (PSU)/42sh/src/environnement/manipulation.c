/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Env manipulation
*/

#include "minishell2.h"
#include "environnement/manipulation.h"
#include "environnement/linked_list_utils.h"

void    add_env_node(shell_t *shell, env_t *new_env)
{
    if (shell->last_env) {
        shell->last_env->next = new_env;
        shell->last_env = new_env;
    } else {
        shell->first_env = new_env;
        shell->last_env = new_env;
    }
}

char    **getenv_arr(shell_t *shell)
{
    env_t *env = shell->first_env;
    char **arr_env = NULL;
    int size = 0;
    int i = 0;

    while (env) {
        size += 1;
        env = env->next;
    }
    arr_env = malloc(sizeof(char *) * (size + 1));
    env = shell->first_env;
    while (env) {
        arr_env[i] = my_strcat2(env->var, "=", -1, 0);
        arr_env[i] = my_strcat2(arr_env[i], env->value, -1, 0);
        env = env->next;
        i += 1;
    }
    arr_env[size] = NULL;
    return (arr_env);
}

env_t    *getenv_var(shell_t *shell, char *var)
{
    env_t *env = shell->first_env;

    while (env) {
        if (my_strcmp(env->var, var) == 0)
            return (env);
        env = env->next;
    }
    return (NULL);
}

void    unsetenv_var(shell_t *shell, char *var)
{
    env_t *env_var = getenv_var(shell, var);

    if (!env_var)
        return;
    if (env_var->next) {
        delete_node(shell, env_var);
    } else {
        delete_last_node(shell, env_var);
    }
    free(env_var);
}

void    setenv_var(shell_t *shell, char *var, char *value)
{
    env_t *new_env = malloc(sizeof(env_t));
    env_t *env_var = NULL;

    new_env->var = var;
    new_env->value = value ? value : "";
    env_var = getenv_var(shell, var);
    if (env_var)
        env_var->value = new_env->value;
    else {
        new_env->next = NULL;
        new_env->prec = shell->last_env;
        add_env_node(shell, new_env);
    }
}