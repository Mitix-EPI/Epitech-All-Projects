/*
** EPITECH PROJECT, 2020
** tests_var_checks.c
** File description:
** tests_var_checks.c
*/

#include "minishell2.h"
#include "variables/manipulation.h"
#include "variables/linked_list_utils.h"
#include "commands.h"
#include <criterion/criterion.h>

Test(check_undefined_vars, shall_retunnnnnn_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command = "PATH";

    memset(shell, 0, 1);
    res = check_undefined_vars(shell, command);
    cr_assert_eq(res, 1);
}

Test(check_undefined_vars, shall_retunnnn_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command = "PATH\ttest\tHOME";

    memset(shell, 0, 1);
    res = check_undefined_vars(shell, command);
    cr_assert_eq(res, 1);
}

Test(exec_command, testsstt1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    int fd[2] = {1, 2};
    char *command = "ls\ntest\nzebi\nls -l";

    res = exec_command(shell, command, fd);
    cr_assert_eq(res, 1);
}