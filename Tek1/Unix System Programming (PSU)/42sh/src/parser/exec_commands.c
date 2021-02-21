/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** exec commands
*/

#include "parser/exec_commands.h"
#include "commands.h"
#include "variables/manipulation.h"

void exec_command_pipe(shell_t *shell, node_t *node)
{
    pid_t pid = 0;
    int fds[2];

    if (node->right->cmd && node->right->cmd[0] == '\0') {
        my_printf("Invalid null command.\n");
        return;
    }
    node->left->fds[0] = node->fds[0];
    node->right->fds[1] = node->fds[1];
    pipe(fds);
    node->right->fds[0] = fds[0];
    node->left->fds[1] = fds[1];
    pid = fork();
    if (!pid) {
        close(fds[0]);
        exec_commands_from_tree(shell, node->left);
        exit(close(fds[1]));
    }
    close(node->left->fds[1]);
    exec_commands_from_tree(shell, node->right);
    wait(&pid);
}

void repeat_cmd(shell_t *shell, node_t *node)
{
    char **cmd_args = my_split_str(my_strdup(node->cmd), " \t");
    int delta = 0;
    int nb = 0;

    if (!cmd_args[1] || !cmd_args[2]) {
        my_printf("repeat: Too few arguments.\n");
        shell->last_exit_code = 1;
        return;
    }
    if (!my_str_isnum(cmd_args[1])) {
        my_printf("repeat: Badly formed number.\n");
        shell->last_exit_code = 1;
        return;
    }
    delta = 7 + my_strlen(cmd_args[1]);
    nb = my_getnbr(cmd_args[1]);
    for (int i = 0; i < nb; i++)
        node->exit_code = exec_command(shell, node->cmd + delta, node->fds);
    shell->last_exit_code = node->exit_code;
}

void exec_commands_from_tree(shell_t *shell, node_t *node)
{
    for (int i = 0; node->sep && separators[i].sep != NULL; i++) {
        if (!my_strcmp(node->sep, separators[i].sep)) {
            separators[i].ptr(shell, node);
            return;
        }
    }
    if (!node->cmd)
        return;
    if (node->cmd[0] == '|' || !(node->cmd = replace_vars(shell, node->cmd))) {
        !node->cmd ? 0 : my_printf("Invalid null command.\n");
        node->exit_code = 1;
        return;
    }
    if (my_strncmp(node->cmd, "repeat", 6)) {
        node->exit_code = exec_command(shell, node->cmd, node->fds);
        shell->last_exit_code = node->exit_code;
        return;
    }
    repeat_cmd(shell, node);
}