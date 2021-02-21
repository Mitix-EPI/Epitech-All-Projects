/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** env init
*/

#include "minishell2.h"
#include "environnement/initialization.h"
#include "environnement/manipulation.h"
#include "commands/env.h"

void    init_env(shell_t *shell, char **env)
{
    char *value = malloc(sizeof(char));
    char **temp = NULL;

    for (int i = 0; env[i]; i += 1) {
        value = malloc(sizeof(char));
        value[0] = '\0';
        temp = my_split(env[i], '=');
        for (int i = 1; temp[i]; i++) {
            i != 1 ? value = my_strcat2(value, "=", -1, 0) : 0;
            value = my_strcat2(value, temp[i], -1, -0);
            free(temp[i]);
        }
        setenv_var(shell, temp[0], value);
        free(temp);
    }
    update_path(shell);
}