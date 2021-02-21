/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** main_name
*/

#include "../include/my.h"

void my_flush(char *str)
{
    for (int i = 0; i < 4096; i++)
        str[i] = 0;
}

int my_fork(char **command, char **envi, char **env)
{
    int stat = 0;
    int pid = 0;

    if ((pid = fork()) == 0) {
        if (my_executer(command, envi, env) == 0) {
            end_program(envi, command[0], 1);
        }
    } else {
        wait(&stat);
        if (WIFSIGNALED(stat))
            print_errors(stat);
    }
    if (stat == 139)
        write(1, "Segmentation fault\n", 19);
    if (stat == 136)
        write(1, "Floating exception\n", 19);
    return (0);
}

int launch_program(char *str, char **envi, char **env, objt_struct_t **head)
{
    str[my_count(str) - 1] = 0;
    node_t *arbol = return_arbol(str);
    node_t *tmp = arbol;

    if (tmp->left == NULL && tmp->right == NULL) {
        execute_command3(tmp, envi, env, head);
        return (0);
    }

    execute_arbol(tmp, envi, env, head);
    return (0);
}

char *get_name(char *str, int *k)
{
    char *tmp = NULL;
    int i = 0;

    for (; str[i] != '=' && str[i]; i++);
    tmp = malloc(sizeof(char) * (i + 1));
    for (; str[*k] != '=' && str[*k]; *k += 1)
        tmp[*k] = str[*k];
    tmp[*k] = 0;
    return (tmp);
}

int mysh(char **env)
{
    objt_struct_t *head = NULL;
    int loop = 0;
    char *str = malloc(sizeof(str) * (4096 + 1));
    size_t size_str = 4096;
    int enter = 0;
    char **envi = return_good_env(env);

    head = set_nodes(head, env);
    do {
        if (isatty(0))
            siginhandler(666);
        my_flush(str);
        if ((enter = getline(&str, &size_str, stdin)) == EOF ||
        my_strcmp(str, "exit\n") == 0) {
            if (isatty(0))
                my_putstr(1, "exit\n");
            end_program(envi, str, 1);
        }
        loop = launch_program(str, envi, env, &head);
    } while (loop == 0);
    return (end_program(envi, str, 0));
}