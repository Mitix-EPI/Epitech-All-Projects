/*
** EPITECH PROJECT, 2020
** tests_alias2.c
** File description:
** tests_alias2.c
*/

#include "aliases/aliases.h"
#include "commands/alias.h"
#include "jobs/fg.h"
#include "minishell2.h"
#include <criterion/criterion.h>

Test(cmd_alias, testttttt1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {NULL};

    add_alias("cd", "ls", &shell->alias);
    add_alias("ls", "cd", &shell->alias);
    res = cmd_alias(shell, command);
    cr_assert_eq(res, 0);
}

Test(cmd_fg, teststtsts1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {NULL};

    res = cmd_fg(shell, command);
    cr_assert_eq(res, 1);
}

Test(cmd_fg, testtsts1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"ls", "salut", "yo", NULL};

    res = cmd_fg(shell, command);
    cr_assert_eq(res, 1);
}