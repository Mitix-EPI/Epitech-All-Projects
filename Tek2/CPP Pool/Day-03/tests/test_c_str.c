/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_c_str
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <string.h>

Test(c_str, should_return_value)
{
    string_t this;

    this.str = strdup("DATA");
    const char *res = c_str(&this);
    cr_assert_str_eq(res, "DATA");
    free(this.str);
}
