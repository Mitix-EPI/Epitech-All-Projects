/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "tree.h"

void parse_pipes_redirections(node_t *node);
void parse_and(node_t *node);
void parse_or(node_t *node);
node_t *parse_command(shell_t *shell, char *command);