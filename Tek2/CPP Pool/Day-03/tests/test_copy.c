/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_copy
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(copy, should_return_number_of_copies_characters)
{
    string_t this;
    char *str = calloc(12, sizeof(char));
    this.str = strdup("Hello World");
    const size_t res = copy(&this, str, 5, 0);
    cr_assert_eq(res, 5);
    cr_assert_str_eq(str, "Hello");
    free(this.str);
    free(str);
}
