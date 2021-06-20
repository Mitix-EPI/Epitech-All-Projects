/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_at
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(at, should_return_false)
{
    string_t this;
    this.str = strdup("Hello World");
    const int res = at(&this, 20);
    cr_assert_eq(res, -1);
    free(this.str);
}

Test(at, should_return_W)
{
    string_t this;
    this.str = strdup("Hello World");
    const int res = at(&this, 6);
    cr_assert_eq(res, 'W');
    free(this.str);
}
