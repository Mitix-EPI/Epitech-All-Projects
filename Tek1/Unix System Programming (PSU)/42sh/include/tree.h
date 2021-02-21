/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#ifndef TREE_H
#define TREE_H

#include "minishell2.h"

typedef struct node_s node_t;

typedef struct node_s {
    char *cmd;
    char *sep;
    int fds[2];
    int exit_code;
    node_t *left;
    node_t *right;
} node_t;

node_t *create_node(char *cmd, char *sep);

#endif