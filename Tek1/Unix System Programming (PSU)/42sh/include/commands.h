/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"
#include "commands/cd.h"
#include "commands/env.h"
#include "commands/set.h"
#include "commands/alias.h"
#include "commands/exit.h"
#include "which/which.h"
#include "history/display_history.h"
#include "where/where.h"
#include "jobs/fg.h"

#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct commands_funcs_s {
    char *command;
    int (*func)(shell_t *, char **);
} commands_funcs_t;

static const commands_funcs_t commands_funcs[] = {
    {"setenv", cmd_setenv},
    {"unsetenv", cmd_unsetenv},
    {"env", cmd_env},
    {"cd", cmd_cd},
    {"exit", cmd_exit},
    {"set", cmd_set},
    {"unset", cmd_unset},
    {"alias", cmd_alias},
    {"unalias", cmd_unalias},
    {"which", which},
    {"where", where},
    {"history", print_history},
    {"fg", cmd_fg},
    {NULL, NULL},
};

int exec_command(shell_t *shell, char *command, int fds[2]);
void check_done(void);

#endif
