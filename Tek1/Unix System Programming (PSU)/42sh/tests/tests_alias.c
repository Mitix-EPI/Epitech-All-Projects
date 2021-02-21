/*
** EPITECH PROJECT, 2020
** tests_alias.c
** File description:
** tests_alias.c
*/

#include "minishell2.h"
#include "aliases/aliases.h"
#include <criterion/criterion.h>

Test(add_alias, should_ret_smth)
{
    alias_t *alias = NULL;

    add_alias("ls", "ls", &alias);
    cr_assert_str_eq(alias->command, "ls");
}

Test(proceed_alias, tst1)
{
    shell_t *shell = malloc(sizeof(shell_t));
    char *command = "ls";
    char *res = NULL;

    add_alias("ls", "cd", &shell->alias);
    add_alias("cd", "ls", &shell->alias);
    res = proceed_alias(shell, command);
    cr_assert_str_eq(res, "");
}

Test(proceed_alias, tste1)
{
    shell_t *shell = malloc(sizeof(shell_t));
    char *command = "cd";
    char *res = NULL;

    add_alias("ls", "cd", &shell->alias);
    res = proceed_alias(shell, command);
    cr_assert_str_eq(res, "ls");
}

Test(proceed_alias, tstee1)
{
    shell_t *shell = malloc(sizeof(shell_t));
    char *command = "ls";
    char *res = NULL;

    add_alias("ls", "cd", &shell->alias);
    res = proceed_alias(shell, command);
    cr_assert_str_eq(res, "ls");
}

Test(proceed_alias, tsteee1)
{
    shell_t *shell = malloc(sizeof(shell_t));
    char *command = NULL;
    char *res = NULL;

    add_alias("ls", "cd", &shell->alias);
    res = proceed_alias(shell, command);
    cr_assert_eq(res, NULL);
}