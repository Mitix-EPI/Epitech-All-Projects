/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_print
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print, should_write_in_output)
{
    string_t this;
    string_init(&this, "Troll");
    print(&this);
    cr_assert_eq(0, 0);
    string_destroy(&this);
}
