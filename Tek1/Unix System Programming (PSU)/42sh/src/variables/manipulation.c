/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Var manipulation
*/

#include "minishell2.h"
#include "variables/manipulation.h"
#include "variables/linked_list_utils.h"

char    **getvar_arr(shell_t *shell)
{
    var_t *node_var = shell->first_var;
    char **arr_vars = NULL;
    int size = 0;
    int i = 0;

    while (node_var) {
        size += 1;
        node_var = node_var->next;
    }
    arr_vars = malloc(sizeof(char *) * (size + 1));
    node_var = shell->first_var;
    while (node_var) {
        arr_vars[i] = my_strcat2(node_var->var, "=", -1, 0);
        arr_vars[i] = my_strcat2(arr_vars[i], node_var->value, -1, 0);
        node_var = node_var->next;
        i += 1;
    }
    arr_vars[size] = NULL;
    return (arr_vars);
}

var_t    *get_var(shell_t *shell, char *var)
{
    var_t *node_var = shell->first_var;

    while (node_var) {
        if (my_strcmp(node_var->var, var) == 0)
            return (node_var);
        node_var = node_var->next;
    }
    return (NULL);
}

char    *replace_vars(shell_t *shell, char *command)
{
    char *var_tmp = NULL;

    for (var_t *var = shell->first_var; var; var = var->next) {
        var_tmp = my_strcat2("$", var->var, -1, 0);
        command = my_str_replace(command, var_tmp, var->value);
        var_tmp = my_strcat2(my_strcat2("${", var->var, -1, 0), "}", -1, 0);
        command = my_str_replace(command, var_tmp, var->value);
    }
    for (env_t *env = shell->first_env; env; env = env->next) {
        var_tmp = my_strcat2("$", env->var, -1, 0);
        command = my_str_replace(command, var_tmp, env->value);
        var_tmp = my_strcat2(my_strcat2("${", env->var, -1, 0), "}", -1, 0);
        command = my_str_replace(command, var_tmp, env->value);
    }
    command = my_str_replace(command, "$?", my_itoa(shell->last_exit_code));
    if (check_undefined_vars(shell, command) == 0)
        return (NULL);
    return (command);
}

void    unset_var(shell_t *shell, char *var)
{
    var_t *node_var = get_var(shell, var);

    if (!node_var)
        return;
    if (node_var->next) {
        delete_node_var(shell, node_var);
    } else {
        delete_last_node_var(shell, node_var);
    }
    free(node_var);
}

void    set_var(shell_t *shell, char *var, char *value)
{
    var_t *new_var = malloc(sizeof(var_t));
    var_t *node_var = NULL;

    new_var->var = var;
    new_var->value = value ? value : "";
    node_var = get_var(shell, var);
    if (node_var)
        node_var->value = new_var->value;
    else {
        new_var->next = NULL;
        new_var->prec = shell->last_var;
        add_node_var(shell, new_var);
    }
}