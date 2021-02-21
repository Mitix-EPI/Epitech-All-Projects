/*
** EPITECH PROJECT, 2020
** tests_where2.c
** File description:
** tests_where2.c
*/

#include "where/where_following.h"
#include "where/where.h"
#include "initialization.h"
#include <criterion/criterion.h>

Test(where, shall_rettttttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"zebi", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = NULL;
    res = where(shell, command);
    cr_assert_eq(res, 1);
}

Test(where, shall_retttttttttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"/ls", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = where(shell, command);
    cr_assert_eq(res, 1);
}

Test(where, shall_retttttttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {NULL, NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = where(shell, command);
    cr_assert_eq(res, 1);
}

Test(where, shall_retttttttt_0)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"cd", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = where(shell, command);
    cr_assert_eq(res, 0);
}

Test(where, shall_retttttzaettttt_1)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"ls", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/";
    res = where(shell, command);
    cr_assert_eq(res, 1);
}