/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Var check
*/

#include "minishell2.h"
#include "variables/manipulation.h"
#include "variables/linked_list_utils.h"

int check_var(shell_t *shell, char *command)
{
    for (var_t *var = shell->first_var; var; var = var->next) {
        if (!my_strcmp(command, var->var))
            return (1);
    }
    for (env_t *var = shell->first_env; var; var = var->next) {
        if (!my_strcmp(command, var->var))
            return (1);
    }
    shell->last_exit_code = 1;
    printf("%s: Undefined variable.\n", command);
    return (0);
}

int check_undefined_vars(shell_t *shell, char *command)
{
    char **tab = my_split_str(my_strdup(command), " \t\n");

    if (!tab)
        return (1);
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] != '$' || my_strlen(tab[i]) < 2 || tab[i][1] == '?')
            continue;
        if (!check_var(shell, tab[i] + 1))
            return (0);
    }
    return (1);
}
