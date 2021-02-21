/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(print_map, display_msg)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    ms.line = 2;

    cr_redirect_stdout();
    print_map(&ms);
    cr_assert_stdout_eq_str("*****\n*   *\n*|||*\n*****\n\n");
}