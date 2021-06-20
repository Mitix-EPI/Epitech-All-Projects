/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_find
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(find_c, should_return_false)
{
    string_t this;
    this.str = strdup("Hello World");
    const int res = find_c(&this, "Nowhere", 0);
    cr_assert_eq(res, -1);
    free(this.str);
}

Test(find_c, should_return_first_pos)
{
    string_t this;
    this.str = strdup("Hello World");
    const int res = find_c(&this, "Worl", 5);
    cr_assert_eq(res, 6);
    free(this.str);
}

Test(find_s, should_return_first_pos)
{
    string_t this;
    string_t tmp;
    this.str = strdup("Hello World");
    tmp.str = strdup("Worl");
    const int res = find_s(&this, &tmp, 5);
    cr_assert_eq(res, 6);
    free(this.str);
    free(tmp.str);
}

Test(find_s, should_return_false)
{
    string_t this;
    string_t tmp;
    this.str = strdup("Hello World");
    tmp.str = strdup("Nowhere");
    const int res = find_s(&this, &tmp, 0);
    cr_assert_eq(res, -1);
    free(this.str);
    free(tmp.str);
}
