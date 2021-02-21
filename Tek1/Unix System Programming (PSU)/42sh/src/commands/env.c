/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Cmd of minishell2
*/

#include "minishell2.h"
#include "environnement/manipulation.h"

void    update_path(shell_t *shell)
{
    env_t *path = getenv_var(shell, "PATH");

    if (path)
        shell->path = path->value;
}

static int    error_handling(char *name)
{
    if (name[0] >= '0' && name[0] <= '9') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    if (!my_str_isalpha(name) && !my_str_isnum(name) && name[0] != '_') {
        my_putstr("setenv: Variable name must contain ");
        my_putstr("alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

void    cmd_env(shell_t *shell, char **argv)
{
    env_t *env = shell->first_env;
    char *env_str = malloc(sizeof(char) * 1);

    (void)argv;
    env_str[0] = '\0';
    while (env) {
        if (env->var != shell->first_env->var)
            env_str = my_strcat2(env_str, "\n", -1, 0);
        env_str = my_strcat2(env_str, env->var, -1, 0);
        env_str = my_strcat2(env_str, "=", -1, 0);
        env_str = my_strcat2(env_str, env->value, -1, 0);
        env = env->next;
    }
    my_printf("%s", env_str);
    if (env_str[0])
        my_printf("\n");
}

int    cmd_setenv(shell_t *shell, char **argv)
{
    for (int i = 0; argv[i]; i += 1) {
        if (i > 1) {
            my_printf("setenv: Too many arguments\n");
            return (1);
        }
    }
    if (argv[0]) {
        if (!error_handling(argv[0]))
            setenv_var(shell, argv[0], argv[1]);
        else
            return (1);
    } else
        cmd_env(shell, NULL);
    update_path(shell);
    return (0);
}

int    cmd_unsetenv(shell_t *shell, char **argv)
{
    for (int i = 0; argv[i]; i += 1) {
        unsetenv_var(shell, argv[i]);
    }
    return (0);
}