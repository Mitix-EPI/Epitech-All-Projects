/*
** EPITECH PROJECT, 2020
** tests_where.c
** File description:
** tests_where.c
*/

#include "where/where_following.h"
#include "where/where.h"
#include "initialization.h"
#include <criterion/criterion.h>

Test(check_valid_command, should_return_1)
{
    int res = 0;
    char *tab[] = {"/bin/ls", "yo", NULL};

    res = check_valid_command(tab);
    cr_assert_eq(res, 1);
}

Test(check_valid_command, should_return_0)
{
    int res = 0;
    char *tab[] = {"salut", "yo", NULL};

    res = check_valid_command(tab);
    cr_assert_eq(res, 0);
}

Test(check_filerc_exist, shall_retun_nothing)
{
    shell_t shell;

    check_filerc_exist();
    init_shell_var(&shell);
    init_history_rc(&shell);
}

Test(where, shall_rettt_0)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"ls", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = where(shell, command);
    cr_assert_eq(res, 0);
}

Test(where, shall_rettttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"zebi", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = where(shell, command);
    cr_assert_eq(res, 1);
}