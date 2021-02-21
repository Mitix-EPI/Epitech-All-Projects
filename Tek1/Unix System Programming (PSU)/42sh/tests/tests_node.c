/*
** EPITECH PROJECT, 2020
** tests_node.c
** File description:
** tests_node.c
*/

#include "tree.h"
#include "minishell2.h"
#include "which/which.h"
#include <criterion/criterion.h>

Test(create_node, zebi)
{
    node_t *node = create_node("salut yo", " ");

    cr_assert_str_eq(node->cmd, "salut yo");
}

Test(which, should_reterunrer_0)
{
    int res = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    char *command[] = {"ls", NULL};

    add_alias("ls", "cd", &shell->alias);
    shell->path = "/usr/local/sbin:/usr/bin:/usr/sbin";
    res = which(shell, command);
    cr_assert_eq(res, 0);
}