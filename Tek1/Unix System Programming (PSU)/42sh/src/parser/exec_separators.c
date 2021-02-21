/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** exec commands
*/

#include "parser/exec_commands.h"
#include "commands.h"

void exec_command_semicolon(shell_t *shell, node_t *node)
{
    exec_commands_from_tree(shell, node->left);
    exec_commands_from_tree(shell, node->right);
}

void exec_command_and(shell_t *shell, node_t *node)
{
    exec_commands_from_tree(shell, node->left);
    if (shell->last_exit_code == 0)
        exec_commands_from_tree(shell, node->right);
}

void exec_command_or(shell_t *shell, node_t *node)
{
    exec_commands_from_tree(shell, node->left);
    if (shell->last_exit_code != 0)
        exec_commands_from_tree(shell, node->right);
}
