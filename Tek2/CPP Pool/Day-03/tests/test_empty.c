/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_empty
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(empty, should_return_true)
{
    string_t this;
    this.str = NULL;
    const int res = empty(&this);
    cr_assert_eq(res, 1);
    clear(&this);
    const int res2 = empty(&this);
    cr_assert_eq(res2, 1);
}

Test(empty, should_return_false)
{
    string_t this;
    this.str = strdup("test");
    const int res = empty(&this);
    cr_assert_eq(res, 0);
    free(this.str);
}
