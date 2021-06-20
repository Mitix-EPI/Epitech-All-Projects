/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_size
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(size, should_return_false)
{
    string_t this;
    this.str = NULL;
    const int res = size(&this);
    cr_assert_eq(res, -1);
}

Test(size, should_return_size)
{
    string_t this;
    this.str = strdup("test");
    const int res = size(&this);
    cr_assert_eq(res, 4);
    free(this.str);
}
