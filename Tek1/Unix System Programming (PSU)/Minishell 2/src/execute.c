/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** execute
*/

#include "../include/my.h"

void loop(char **command, char ***envs, node_t *tmp)
{
    for (int i = 0; envs[1][i] != NULL; i++)
        if (access(my_strcat(envs[1][i], command[0]), X_OK) == 0) {
            dup2(tmp->pipes[0], 0);
            dup2(tmp->pipes[1], 1);
            if (execve(my_strcat(envs[1][i], command[0]), command, envs[0])
            < 0) {
                my_putstr(tmp->pipes[1], my_strcat(envs[1][i], command[0]));
                my_putstr(tmp->pipes[1], ": Command not found.\n");
            }
            close(tmp->pipes[0]);
            close(tmp->pipes[1]);
        }
    exit(1);
}

void my_exec(char **command, char ***envs, node_t *tmp)
{
    int in = dup(0);
    int out = dup(1);
    int pid = fork();

    if (pid == 0) {
        loop(command, envs, tmp);
    } else {
        wait(&pid);
        close(tmp->pipes[1]);
        dup2(in, 0);
        dup2(out, 1);
        return;
    }
}

int execute_local_commands(char **command, char **envi, char **env)
{
    for (int i = 0; envi[i] != NULL; i++)
        if (access(my_strcat(envi[i], command[0]), X_OK) == 0) {
            if (execve(my_strcat(envi[i], command[0]), command, env) == -1
            && errno != ENOEXEC) {
                my_putstr(1, my_strcat(envi[i], command[0]));
                my_putstr(1, ": Permission denied.\n");
                return (1);
            }
            if (errno == ENOEXEC) {
                my_putstr(1, my_strcat(envi[i], command[0]));
                my_putstr(1, ": Exec format error. Wrong Architecture.\n");
                return (1);
            }
        }
    return (0);
}

int execute_executable(char **command, char **env)
{
    if (access(command[0], X_OK) == 0) {
        if (execve(command[0], command, env) == -1 && errno != ENOEXEC) {
            my_putstr(1, command[0]);
            my_putstr(1, ": Permission denied.\n");
            return (1);
        }
        if (errno == ENOEXEC) {
                my_putstr(1, command[0]);
                my_putstr(1, ": Exec format error. Wrong Architecture.\n");
                return (1);
            }
    }
    return (0);
}

int my_executer(char **command, char **envi, char **env)
{
    if (execute_local_commands(command, envi, env) == 1)
        return (1);
    if (execute_executable(command, env) == 1)
        return (1);
    my_putstr(1, command[0]);
    my_putstr(1, ": Command not found.\n");
    return (0);
}
