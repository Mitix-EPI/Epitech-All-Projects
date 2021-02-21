/*
** EPITECH PROJECT, 2020
** tests_history.c
** File description:
** tests_history.c
*/

#include "history/history.h"
#include "tree.h"
#include "history/display_history.h"
#include <criterion/criterion.h>

Test(is_historyable, should_return__1)
{
    int res = 0;
    char *command = "   \t   \n";

    res = is_historyable(command);
    cr_assert_eq(res, 1);
}

Test(is_historyable, should_return__0)
{
    int res = 0;
    char *command = "salut";

    res = is_historyable(command);
    cr_assert_eq(res, 0);
}

Test(print_history, shoudl_return_0)
{
    int res = 0;
    shell_t shell;
    char *command[] = {"test", NULL};

    shell.history_path = "tests/tests_history.c";
    check_history_file_exist(&shell);
    res = print_history(&shell, command);
    cr_assert_eq(res, 0);
}

Test(print_history, shoudl_return_1_1)
{
    int res = 0;
    shell_t shell;
    char *command[] = {"test", NULL};

    shell.history_path = NULL;
    res = print_history(&shell, command);
    cr_assert_eq(res, 1);
}

Test(print_history, shoudl_return_1_2)
{
    int res = 0;
    shell_t shell;
    char *command[] = {"test", NULL};

    shell.history_path = "false_path";
    res = print_history(&shell, command);
    cr_assert_eq(res, 1);
}