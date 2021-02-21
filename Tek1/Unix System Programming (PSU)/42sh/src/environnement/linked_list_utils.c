/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Linked list utils
*/

#include "minishell2.h"
#include "environnement/linked_list_utils.h"

void   delete_node(shell_t *shell, env_t *env_var)
{
    if (env_var->prec) {
        env_var->prec->next = env_var->next;
        env_var->next->prec = env_var->prec;
    } else {
        shell->first_env = env_var->next;
        env_var->next->prec = NULL;
    }
}

void    delete_last_node(shell_t *shell, env_t *env_var)
{
    if (shell->first_env != shell->last_env) {
        shell->last_env = env_var->prec;
        env_var->prec->next = NULL;
    } else {
        shell->first_env = NULL;
        shell->last_env = NULL;
    }
}