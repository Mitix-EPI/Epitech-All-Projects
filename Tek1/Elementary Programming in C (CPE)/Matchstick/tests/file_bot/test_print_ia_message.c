/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(print_ia_message, return_IA_turn_txt)
{
    cr_redirect_stdout();
    print_ia_message(1, 1);
    cr_assert_stdout_eq_str("AI removed 1 match(es) from line 1\n");
}