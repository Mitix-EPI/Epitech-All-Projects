/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** tree
*/

#include "tree.h"

node_t *create_node(char *cmd, char *sep)
{
    node_t *node = malloc(sizeof(node_t));

    node->cmd = NULL;
    node->sep = NULL;
    node->left = NULL;
    node->right = NULL;
    node->exit_code = 0;
    if (cmd)
        node->cmd = cmd;
    if (sep)
        node->sep = sep;
    node->fds[0] = 0;
    node->fds[1] = 1;
    return (node);
}
