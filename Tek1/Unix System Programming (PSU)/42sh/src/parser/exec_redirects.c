/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** exec redirects
*/

#include "parser/exec_commands.h"

void exec_command_redirect_r(shell_t *shell, node_t *node)
{
    int fd = open(STRTOWA(node->right->cmd)[0],
        O_WRONLY | O_CREAT | O_TRUNC, 0664);

    node->left->fds[0] = node->fds[0];
    node->left->fds[1] = fd;
    exec_commands_from_tree(shell, node->left);
    close(fd);
}

void exec_command_redirect_l(shell_t *shell, node_t *node)
{
    int fd = open(STRTOWA(node->right->cmd)[0], O_RDONLY);

    if (fd < 0) {
        my_printf("%s: No such file or directory.\n", node->right->cmd);
        return;
    }
    node->left->fds[0] = fd;
    node->left->fds[1] = node->fds[1];
    exec_commands_from_tree(shell, node->left);
    close(fd);
}

void exec_command_redirect_dr(shell_t *shell, node_t *node)
{
    int fd = open(STRTOWA(node->right->cmd)[0],
        O_WRONLY | O_CREAT | O_APPEND, 0664);

    node->left->fds[0] = node->fds[0];
    node->left->fds[1] = fd;
    exec_commands_from_tree(shell, node->left);
    close(fd);
}

void exec_command_redirect_dl(shell_t *shell, node_t *node)
{
    int fd = open(".tmp_redirect", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;

    node->right->cmd = my_split_str(node->right->cmd, " \t\n")[0];
    if (isatty(0) > 0)
            my_printf("? ");
    while ((read = getline(&buffer, &len, stdin)) != -1) {
        if (!my_strcmp(buffer, my_strcat2(node->right->cmd, "\n", -1, 0)))
            break;
        if (isatty(0) > 0)
            my_printf("? ");
        write(fd, buffer, my_strlen(buffer));
    }
    close(fd);
    fd = open(".tmp_redirect", O_RDONLY);
    node->left->fds[0] = fd;
    exec_commands_from_tree(shell, node->left);
    close(fd);
    remove(".tmp_redirect");
}