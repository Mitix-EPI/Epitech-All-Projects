/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_assign
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(assign_c, should_update_str_of_this)
{
    string_t this;

    this.str = malloc(sizeof(char) * 2);
    this.str[0] = 'w';
    this.str[1] = '\0';
    assign_c(&this, "UPDATE");
    cr_assert_str_eq(this.str, "UPDATE");
    free(this.str);
}

Test(assign_s, should_update_str_of_this_struct)
{
    string_t this;
    string_t tmp_this;

    this.str = malloc(sizeof(char) * 2);
    this.str[0] = 'w';
    this.str[1] = '\0';
    tmp_this.str = malloc(sizeof(char) * 2);
    tmp_this.str[0] = 'o';
    tmp_this.str[1] = '\0';
    assign_s(&this, &tmp_this);
    cr_assert_str_eq(this.str, "o");
    free(this.str);
    free(tmp_this.str);
}
