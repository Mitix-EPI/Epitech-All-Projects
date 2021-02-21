/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#ifndef EXEC_COMMANDS_H
#define EXEC_COMMANDS_H

#include "tree.h"
#include "fcntl.h"

typedef struct separators_s {
    char *sep;
    void (*ptr)(shell_t *, node_t *);
} separators_t;

void exec_command_semicolon(shell_t *, node_t *);
void exec_command_pipe(shell_t *, node_t *);
void exec_command_redirect_r(shell_t *, node_t *);
void exec_command_redirect_l(shell_t *, node_t *);
void exec_command_redirect_dr(shell_t *, node_t *);
void exec_command_redirect_dl(shell_t *, node_t *);
void exec_command_and(shell_t *, node_t *);
void exec_command_or(shell_t *, node_t *);

void exec_commands_from_tree(shell_t *, node_t *);

static const separators_t separators[] = {
    {";", &exec_command_semicolon},
    {"|", &exec_command_pipe},
    {">", &exec_command_redirect_r},
    {"<", &exec_command_redirect_l},
    {">>", &exec_command_redirect_dr},
    {"<<", &exec_command_redirect_dl},
    {"||", &exec_command_or},
    {"&&", &exec_command_and},
    {NULL, NULL}
};

#endif