/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_insert
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(insert_c, should_insert_str_into_this_str)
{
    string_t *this = (string_t *)calloc(1, sizeof(string_t));
    string_init(this, "Hello World");
    insert_c(this, 6, "Pas ");
    cr_assert_str_eq(this->str, "Hello Pas World");
    insert_c(this, 30, "PLop");
    cr_assert_str_eq(this->str, "Hello Pas WorldPLop");
    insert_c(this, 4, NULL);
    string_destroy(this);
}

Test(insert_s, should_insert_strutc_str_into_this_str)
{
    string_t this;
    string_t tmp;

    this.str = strdup("Hello World");
    tmp.str = strdup("Pas ");
    insert_s(&this, 6, &tmp);
    cr_assert_str_eq(this.str, "Hello Pas World");
    insert_s(&this, 30, &tmp);
    cr_assert_str_eq(this.str, "Hello Pas WorldPas ");
    insert_s(&this, 6, NULL);
    tmp.str = NULL;
    insert_s(&this, 6, &tmp);
    free(this.str);
    free(tmp.str);
}
