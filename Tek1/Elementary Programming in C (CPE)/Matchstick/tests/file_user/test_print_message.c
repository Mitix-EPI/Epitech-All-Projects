/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(print_message, display_msg)
{
    cr_redirect_stdout();
    print_message(1, 1);
    cr_assert_stdout_eq_str("Player removed 1 match(es) from line 1\n");
}