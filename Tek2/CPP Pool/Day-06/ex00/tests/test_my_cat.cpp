/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** test_my_cat
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../mycat.hpp"

Test(argError, should_display_error)
{
    cr_redirect_stderr();
    int res = argError(1);
    cr_assert_stderr_eq_str("my_cat: Usage: ./my_cat file [...]\n");
    cr_assert_eq(res, 1);
}

Test(argError, should_return_0)
{
    int res = argError(2);
    cr_assert_eq(res, 0);
}
