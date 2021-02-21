/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** parser
*/

#include "my.h"
#include "parser/parser.h"
#include "variables/manipulation.h"
#include "globbing/glob.h"
#include "aliases/aliases.h"

void parse_semi_colons(node_t *node)
{
    for (int i = my_strlen(node->cmd) - 1; i > 0; i--) {
        if (node->cmd[i] != ';')
            continue;
        node->right = create_node(node->cmd + i + 1, NULL);
        node->cmd[i] = '\0';
        node->left = create_node(node->cmd, NULL);
        node->sep = ";";
        node->cmd = NULL;
        parse_semi_colons(node->left);
        parse_semi_colons(node->right);
        break;
    }
}

int is_double_redirection(node_t *node, int i)
{
    char *cmd = node->cmd;

    if (i == 0)
        return (0);
    if (cmd[i] != '<' || cmd[i - 1] != '<')
        if (cmd[i] != '>' || cmd[i - 1] != '>')
            return (0);
    node->right = create_node(node->cmd + i + 1, NULL);
    node->cmd[i - 1] = '\0';
    node->left = create_node(node->cmd, NULL);
    switch (cmd[i]) {
        case '>':
            node->sep = ">>";
            break;
        case '<':
            node->sep = "<<";
    }
    node->cmd = NULL;
    parse_pipes_redirections(node->left);
    parse_pipes_redirections(node->right);
    return (1);
}

void parse_pipes_redirections(node_t *node)
{
    if (node->cmd == NULL) {
        parse_pipes_redirections(node->left);
        parse_pipes_redirections(node->right);
        return;
    }
    for (int i = my_strlen(node->cmd) - 1; i > 0; i--) {
        if (is_double_redirection(node, i) == 1)
            return;
        if (node->cmd[i] != '|' && node->cmd[i] != '>' && node->cmd[i] != '<')
            continue;
        node->right = create_node(node->cmd + i + 1, NULL);
        node->sep = my_char_tostring(node->cmd[i]);
        node->cmd[i] = '\0';
        node->left = create_node(node->cmd, NULL);
        node->cmd = NULL;
        parse_pipes_redirections(node->left);
        parse_pipes_redirections(node->right);
        break;
    }
}

node_t *parse_command(shell_t *shell, char *command)
{
    node_t *node = NULL;

    command = proceed_alias(shell, command);
    node = create_node(command, NULL);
    parse_semi_colons(node);
    parse_or(node);
    parse_and(node);
    parse_pipes_redirections(node);
    return (node);
}