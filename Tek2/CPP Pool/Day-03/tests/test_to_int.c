/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_to_int
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(to_int, should_convert_str_to_int)
{
    string_t this;

    this.str = strdup("666");
    const int res = to_int(&this);
    cr_assert_eq(res, 666);
    free(this.str);
}
