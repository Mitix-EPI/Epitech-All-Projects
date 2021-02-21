/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(checks_buff_size, return_0)
{
    matchstick_t ms;
    char *str = "-1";
    char *str2 = "101";

    cr_assert_eq(checks_buff_size(str, &ms), 0);
    cr_assert_eq(checks_buff_size(str2, &ms), 0);
}

Test(checks_buff_size, return_1)
{
    matchstick_t ms;
    char *str = "3";

    cr_assert_eq(checks_buff_size(str, &ms), 1);
}