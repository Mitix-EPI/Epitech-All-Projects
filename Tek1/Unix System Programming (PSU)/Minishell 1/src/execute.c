/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** execute
*/

#include "../include/my.h"

int execute_local_commands(char **command, char **envi, char **env)
{
    for (int i = 0; envi[i] != NULL; i++)
        if (access(my_strcat(envi[i], command[0]), X_OK) == 0) {
            if (execve(my_strcat(envi[i], command[0]), command, env) == -1
            && errno != ENOEXEC) {
                my_putstr(my_strcat(envi[i], command[0]));
                my_putstr(": Permission denied.\n");
                return (1);
            }
            if (errno == ENOEXEC) {
                my_putstr(my_strcat(envi[i], command[0]));
                my_putstr(": Exec format error. Wrong Architecture.\n");
                return (1);
            }
        }
    return (0);
}

int execute_executable(char **command, char **envi, char **env)
{
    if (access(command[0], X_OK) == 0) {
        if (execve(command[0], command, env) == -1 && errno != ENOEXEC) {
            my_putstr(command[0]);
            my_putstr(": Permission denied.\n");
            return (1);
        }
        if (errno == ENOEXEC) {
                my_putstr(command[0]);
                my_putstr(": Exec format error. Wrong Architecture.\n");
                return (1);
            }
    }
    return (0);
}

int my_executer(char **command, char **envi, char **env)
{
    if (execute_local_commands(command, envi, env) == 1)
        return (1);
    if (execute_executable(command, envi, env) == 1)
        return (1);
    my_putstr(command[0]);
    my_putstr(": Command not found.\n");
    return (0);
}