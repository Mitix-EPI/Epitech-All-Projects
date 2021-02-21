/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Linked list utils
*/

#include "minishell2.h"
#include "variables/linked_list_utils.h"

void    add_node_var(shell_t *shell, var_t *new_var)
{
    if (shell->last_var) {
        shell->last_var->next = new_var;
        shell->last_var = new_var;
    } else {
        shell->first_var = new_var;
        shell->last_var = new_var;
    }
}

void   delete_node_var(shell_t *shell, var_t *var)
{
    if (var->prec) {
        var->prec->next = var->next;
        var->next->prec = var->prec;
    } else {
        shell->first_var = var->next;
        var->next->prec = NULL;
    }
}

void    delete_last_node_var(shell_t *shell, var_t *var)
{
    if (shell->first_var != shell->last_var) {
        shell->last_var = var->prec;
        var->prec->next = NULL;
    } else {
        shell->first_var = NULL;
        shell->last_var = NULL;
    }
}