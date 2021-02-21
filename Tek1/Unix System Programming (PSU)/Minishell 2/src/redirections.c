/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirections
*/

#include "../include/my.h"

void execute_left_simple(char *file, node_t *tmp, char ***envs,
objt_struct_t **head)
{
    int fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
    int pid = fork();
    int in = dup(tmp->left->pipes[1]);

    if (pid == 0) {
        dup2(fd, tmp->left->pipes[1]);
        execute_arbol(tmp->left, envs[1], envs[0], head);
        exit(0);
    } else {
        wait(&pid);
        dup2(in, tmp->left->pipes[1]);
        close(in);
    }
}

void execute_left_double(char *file, node_t *tmp, char ***envs,
objt_struct_t **head)
{
    int fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0777);
    int pid = fork();
    int in = dup(tmp->left->pipes[1]);

    if (pid == 0) {
        dup2(fd, tmp->left->pipes[1]);
        execute_arbol(tmp->left, envs[1], envs[0], head);
        exit(0);
    } else {
        wait(&pid);
        dup2(in, tmp->left->pipes[1]);
        close(in);
    }
}

void execute_right_simple(char ***args, char ***envs, node_t *tmp,
objt_struct_t **head)
{
    int fd = open(args[1][0], O_RDONLY);
    int in = dup(tmp->left->pipes[0]);
    int pid = 0;


    pid = fork();
    if (fd == -1)
        return;
    if (pid == 0) {
        dup2(fd, tmp->left->pipes[0]);
        execute_arbol(tmp->left, envs[1], envs[0], head);
    } else {
        wait(&pid);
        dup2(in, tmp->left->pipes[0]);
        close(in);
    }
}
