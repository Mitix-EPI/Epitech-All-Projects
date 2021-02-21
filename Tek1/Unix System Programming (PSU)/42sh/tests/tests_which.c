/*
** EPITECH PROJECT, 2020
** tests_which.c
** File description:
** tests_which.c
*/

#include "minishell2.h"
#include "which/which.h"
#include <criterion/criterion.h>

Test(which, shall_retttun_0)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"zebi", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = which(shell, command);
    cr_assert_eq(res, 1);
}

Test(which, shall_retttttttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {NULL, NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = which(shell, command);
    cr_assert_eq(res, 1);
}

Test(which, shall_retttttttt_0)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"cd", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = which(shell, command);
    cr_assert_eq(res, 0);
}

Test(which, shall_retttttzaettttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"ls", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/";
    res = which(shell, command);
    cr_assert_eq(res, 1);
}

Test(which, should_reterunrer_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"ls", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = NULL;
    res = which(shell, command);
    cr_assert_eq(res, 1);
}