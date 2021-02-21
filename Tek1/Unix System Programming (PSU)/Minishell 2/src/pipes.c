/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipes
*/

#include "../include/my.h"

void execute_pipe(char ***envs, node_t *tmp, objt_struct_t **head)
{
    int pipes[2] = {0};

    tmp->left->pipes[0] = tmp->pipes[0];
    tmp->right->pipes[1] = tmp->pipes[1];
    pipe(pipes);
    tmp->right->pipes[0] = pipes[0];
    tmp->left->pipes[1] = pipes[1];
    pipe_everything(envs, tmp, head);
}

void pipe_everything(char ***envs, node_t *tmp, objt_struct_t **head)
{
    int pid = 0;

    pid = fork();
    if (pid == 0) {
        close(tmp->right->pipes[0]);
        execute_arbol(tmp->left, envs[1], envs[0], head);
        close(tmp->left->pipes[1]);
        exit(0);
    } else {
        close(tmp->left->pipes[1]);
        execute_arbol(tmp->right, envs[1], envs[0], head);
        wait(&pid);
    }
}
