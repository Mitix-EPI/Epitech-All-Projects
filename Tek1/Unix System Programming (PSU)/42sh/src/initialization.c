/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Initizalization of minishell2
*/

#include "minishell2.h"
#include "prompt.h"
#include "environnement/initialization.h"
#include "history/fill_linked_list_on_start.h"
#include "variables/initialization.h"
#include "scripting/handle_file.h"
#include "environnement/manipulation.h"

void check_filerc_exist(void)
{
    FILE *fs = NULL;

    fs = fopen(".42shrc", "rb+");
    if (fs == NULL) {
        fs = fopen(".42shrc", "wb");
        fprintf(fs, "#!/bin/42sh\n");
    }
    fclose(fs);
}

void    free_all(shell_t *shell)
{
    env_t *env = shell->first_env;
    env_t *tmp = NULL;

    while (env) {
        if (tmp)
            free(tmp);
        tmp = env->next;
        free(env);
        env = tmp;
    }
    free(shell);
}

void init_shell_var(shell_t *shell)
{
    shell->first_env = NULL;
    shell->last_env = NULL;
    shell->history = NULL;
    shell->alias = NULL;
    shell->first_var = NULL;
    shell->last_var = NULL;
    shell->h_index = 0;
    shell->history_path = NULL;
    shell->path_rc = NULL;
    shell->path = NULL;
}

void init_history_rc(shell_t *shell)
{
    char *path_history = NULL;
    char *path_rc = NULL;
    env_t *home;

    shell->cur_history = NULL;
    home = getenv_var(shell, "HOME");
    if (home == NULL || home->value == NULL)
        return;
    path_history = my_strcat2(home->value, "/.42sh_history", -1, 0);
    path_rc = my_strcat2(home->value, "/.42shrc", -1, 0);
    if (path_history != NULL)
        shell->history_path = my_strdup(path_history);
    if (path_rc != NULL)
        shell->path_rc = my_strdup(path_rc);
}

int    initialize(char **env, int enable_ncurse)
{
    shell_t *shell = malloc(sizeof(shell_t));

    init_shell_var(shell);
    init_env(shell, env);
    init_vars(shell, env);
    init_history_rc(shell);
    fill_history_linked_list(shell);
    handle_file(shell, shell->path_rc);
    read_input(shell, enable_ncurse);
    return (0);
}