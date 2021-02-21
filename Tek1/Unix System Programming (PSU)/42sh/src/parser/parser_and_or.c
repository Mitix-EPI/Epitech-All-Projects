/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** parser and or
*/

#include "my.h"
#include "parser/parser.h"

void parse_or(node_t *node)
{
    if (node->cmd == NULL) {
        parse_or(node->left);
        parse_or(node->right);
        return;
    }
    for (int i = my_strlen(node->cmd) - 1; i > 0; i--) {
        if (node->cmd[i] != '|' || node->cmd[i - 1] != '|')
            continue;
        node->right = create_node(node->cmd + i + 1, NULL);
        node->cmd[i - 1] = '\0';
        node->left = create_node(node->cmd, NULL);
        node->sep = "||";
        node->cmd = NULL;
        parse_or(node->left);
        parse_or(node->right);
        return;
    }
}

void parse_and(node_t *node)
{
    if (node->cmd == NULL) {
        parse_and(node->left);
        parse_and(node->right);
        return;
    }
    for (int i = my_strlen(node->cmd) - 1; i > 0; i--) {
        if (node->cmd[i] != '&' || node->cmd[i - 1] != '&')
            continue;
        node->right = create_node(node->cmd + i + 1, NULL);
        node->cmd[i - 1] = '\0';
        node->left = create_node(node->cmd, NULL);
        node->sep = "&&";
        node->cmd = NULL;
        parse_and(node->left);
        parse_and(node->right);
        return;
    }
}