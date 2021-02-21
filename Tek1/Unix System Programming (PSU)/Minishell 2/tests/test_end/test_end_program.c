/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_end_program
*/

#include <criterion/criterion.h>
#include "../../include/my.h"

Test(end_program, return_0)
{
    char *str1 = malloc(sizeof(char) * 2);
    char **array = malloc(sizeof(char *) * 2);
    array[0] = malloc(sizeof(char) * 1);
    array[1] = NULL;

    cr_assert_eq(end_program(array, str1, 0), 0);
}

Test(end_program, exit_0)
{
    char *str1 = malloc(sizeof(char) * 2);
    char **array = malloc(sizeof(char *) * 2);
    array[0] = malloc(sizeof(char) * 1);
    array[1] = NULL;

    cr_assert_eq(end_program(array, str1, 1), 0);
}