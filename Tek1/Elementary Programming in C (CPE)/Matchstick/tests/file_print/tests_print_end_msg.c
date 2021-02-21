/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(print_end_msg, display_msg_win)
{
    char *str = "I lost... snif... but I'll get you next line!!\n";
    cr_redirect_stdout();
    print_end_msg(1);
    cr_assert_stdout_eq_str(str);
}

Test(print_end_msg, display_msg_loose)
{
    cr_redirect_stdout();
    print_end_msg(2);
    cr_assert_stdout_eq_str("You lost, too bad...\n");
}