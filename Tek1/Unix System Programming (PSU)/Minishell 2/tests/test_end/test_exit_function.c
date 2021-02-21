/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_exit_function
*/

#include <criterion/criterion.h>
#include "../../include/my.h"

Test(exit_function, not_returning_0)
{
    char **array = malloc(sizeof(char *) * 2);
    array[0] = malloc(sizeof(char) * 1);
    array[1] = NULL;
    char **command = malloc(sizeof(char *) * 2);
    command[0] = malloc(sizeof(char) * 1);
    command[1] = NULL;
    char *str = malloc(sizeof(char) * 2);

    cr_assert_eq(exit_function(array, command, str), 0);
}