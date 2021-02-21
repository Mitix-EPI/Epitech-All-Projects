/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** functions
*/

#include "../include/my.h"

int cd(char **command, objt_struct_t **head)
{
    static char old_pwd[4096];
    size_t size = 4096;
    char tmp[4096];
    static int first_time = 1;

    if (first_time) {
        getcwd(old_pwd, size);
        first_time = 0;
    }
    getcwd(tmp, size);
    if (!command[1])
        cd_home(head);
    else if (my_strcmp(command[1], "-") == 0) {
        chdir(old_pwd);
    } else
        if (chdir(command[1]) == -1) {
            my_putstr(command[1]);
            my_putstr(": Not a directory.\n");
        }
    my_strcpy(old_pwd, tmp);
    return (0);
}

int my_unsetenv(char **command, objt_struct_t **head)
{
    if (!command[1])
        my_putstr("unsetenv: Too few arguments.\n");
    else
        if (exist_node(command[1], *head) == 1)
            remove_node(command[1], *head);
    return (0);
}

int my_env(objt_struct_t **head)
{
    display(*head);
    return (0);
}

int my_setenv(char **command, objt_struct_t **head)
{
    if (!command[1]) {
        display(*head);
        return (0);
    }
    if (!command[2])
        command[2] = "";
    if (my_str_isalpha2(command[1]) == 0 || my_str_isalpha1(command[2]) == 0) {
        my_putstr("setenv: Variable name must contain ");
        my_putstr("alphanumeric characters.\n");
        return (0);
    }
    if (exist_node(command[1], *head) == 1)
        modify_node(command[1], *head, command[2]);
    else
        *head = add_node_at_the_end(command[1], command[2], *head);
    return (0);
}
