/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** commands
*/

#include "minishell2.h"
#include "commands.h"
#include "prompt.h"
#include "exec.h"
#include "scripting/handle_file.h"
#include "globbing/glob.h"

int check_for_builtin(shell_t *shell, char **arr_command, int fds[2])
{
    int status = 0;

    for (int i = 0; commands_funcs[i].command; i += 1) {
        if (my_strcmp(arr_command[0], commands_funcs[i].command) == 0) {
            dup2(fds[0], 0);
            dup2(fds[1], 1);
            status = commands_funcs[i].func(shell, arr_command + 1);
            return (status);
        }
    }
    return (-1);
}

void is_job_controlled(shell_t *shell, char *command)
{
    int i = my_strlen(command) - 1;

    for (; i > 0; i -= 1)
        if (command[i] != ' ' && command[i] != '\t')
            break;
    shell->job_control = (command[i] == '&') ? 1 : 0;
    if (shell->job_control)
        command[i] = 0;
}

int exec_command(shell_t *shell, char *command, int fds[2])
{
    char **arr_command = NULL;
    char *path_command = NULL;
    int status = 1;

    if (command[0] == '\0')
        return (1);
    is_job_controlled(shell, command);
    arr_command = my_split_str(my_strdup(command), " \t\n");
    if (!arr_command[0])
        return (1);
    arr_command = proceed_globbing(shell, arr_command);
    if ((status = check_for_builtin(shell, arr_command, fds)) != -1)
        return (status);
    path_command = get_binary_name(shell, arr_command[0]);
    if (handle_file(shell, arr_command[0]) != -1)
        return (0);
    if (path_command)
        status = exec_binary(shell, path_command, arr_command, fds);
    return (status);
}
