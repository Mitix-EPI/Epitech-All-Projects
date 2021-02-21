/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** exec
*/

#include "minishell2.h"
#include "environnement/manipulation.h"
#include "exec.h"
#include "prompt.h"

void    display_status(int status)
{

    if (!WIFSIGNALED(status))
        return;
    switch (WTERMSIG(status)) {
        case SIGSEGV:
            my_putstr("Segmentation fault");
            break;
        case SIGFPE:
            my_putstr("Floating exception");
            break;
    }
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)");
    my_putstr("\n");
}

void    check_fork_validity(pid_t process)
{
    if (process < 0) {
        perror("fork");
        return;
    }
}

char    *get_binary_name(shell_t *shell, char *command)
{
    char **path = NULL;
    char *tmp = NULL;

    if (access(command, X_OK) == 0 && my_strstr(command, "/"))
        return (command);
    if (!shell->path || (strlen(shell->path) == 1 && shell->path[0] == '/')) {
        my_printf("%s: Command not found.\n", command);
        return (NULL);
    }
    path = my_split(shell->path, ':');
    for (int i = 0; path[i]; i += 1) {
        tmp = my_strcat2(path[i], "/", -1, 0);
        tmp = my_strcat2(tmp, command, -1, 0);
        if (access(tmp, X_OK) == 0) {
            return (tmp);
        }
    }
    my_printf("%s: Command not found.\n", command);
    return (NULL);
}

void    create_dup2(int fds[2])
{
    dup2(fds[0], 0);
    dup2(fds[1], 1);
}

int    exec_binary(shell_t *shell, char *command, char **argv, int fds[2])
{
    char **env = NULL;
    int status = 0;
    int fds_base[2] = {dup(0), dup(1)};
    pid_t process = fork();

    check_fork_validity(process);
    if (process == 0) {
        create_dup2(fds);
        env = getenv_arr(shell);
        execve(command, argv, !env[0] ? NULL : env);
        close(fds[0]);
        disp_error(command, errno);
        close(fds[1]);
        exit(0);
    }
    control_job(shell, process, &status, argv);
    close(fds[1]);
    create_dup2(fds_base);
    display_status(status);
    return (WEXITSTATUS(status));
}