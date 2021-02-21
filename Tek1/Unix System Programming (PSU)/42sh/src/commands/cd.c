/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Cd of minishell2
*/

#include "minishell2.h"
#include "environnement/manipulation.h"

void    set_old_pwd_on_path(shell_t *shell)
{
    char path[4096];

    getcwd(path, 4095);
    setenv_var(shell, "OLDPWD", my_strdup(path));
}

void    set_pwd_on_path(shell_t *shell)
{
    char path[4096];

    getcwd(path, 4095);
    setenv_var(shell, "PWD", my_strdup(path));
}

void    change_dir(shell_t *shell, char *dir)
{
    set_old_pwd_on_path(shell);
    chdir(dir);
    set_pwd_on_path(shell);
}

int    cmd_cd(shell_t *shell, char **argv)
{
    char path[4096];
    FILE *fs = argv[0] ? fopen(argv[0], "r") : NULL;

    getcwd(path, 4095);
    if (argv[0] && my_strcmp(argv[0], "-") != 0 && !opendir(argv[0])) {
        if (fs == NULL)
            my_printf("%s: No such file or directory.\n", argv[0]);
        else
            my_printf("%s: Not a directory.\n", argv[0]);
        return (1);
    }
    if (argv[0] == NULL) {
        if (getenv_var(shell, "HOME"))
            change_dir(shell, getenv_var(shell, "HOME")->value);
    } else if (my_strcmp(argv[0], "-") == 0) {
        if (getenv_var(shell, "OLDPWD") == NULL)
            return (1);
        change_dir(shell, getenv_var(shell, "OLDPWD")->value);
    } else
        change_dir(shell, argv[0]);
    return (0);
}