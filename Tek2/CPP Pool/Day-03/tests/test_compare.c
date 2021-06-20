/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_compare
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(compare_c, should_return_0)
{
    string_t this;
    this.str = strdup("Hello World");
    const int res = compare_c(&this, "Hello World");
    cr_assert_eq(res, 0);
    free(this.str);
}

Test(compare_s, should_return_0)
{
    string_t this;
    string_t tmp;
    this.str = strdup("Hello World");
    tmp.str = strdup("Hello World");
    const int res = compare_s(&this, &tmp);
    cr_assert_eq(res, 0);
    free(this.str);
    free(tmp.str);
}
