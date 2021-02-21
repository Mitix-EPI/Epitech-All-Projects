/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** env init
*/

#include "minishell2.h"
#include "variables/initialization.h"
#include "variables/manipulation.h"
#include "commands/set.h"

void    init_vars(shell_t *shell, char **env)
{
    (void)env;
    shell->last_exit_code = 0;
    set_var(shell, "shell", "42sh");
}