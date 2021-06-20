/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_join
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(join_c, should_get_array_joined)
{
    char **tmp = (char **)calloc(3, sizeof(char *));
    tmp[0] = strdup("Sophie");
    tmp[1] = strdup("<3");
    string_t this;

    string_init(&this, "Test");
    join_c(&this, ' ', (const char * const *)tmp);
    cr_assert_str_eq(this.str, "Sophie <3");
    join_c(&this, ' ', NULL);
    string_destroy(&this);
    join_c(NULL, ' ', (const char * const *)tmp);
    free(tmp[0]);
    free(tmp[1]);
    free(tmp);
}

Test(join_s, should_get_array_joined)
{
    string_t this;
    string_t **tmp = calloc(3, sizeof(string_t *));

    tmp[0] = calloc(1, sizeof(string_t *));
    tmp[1] = calloc(1, sizeof(string_t *));
    string_init(tmp[0], "Lol");
    string_init(tmp[1], "lel");
    string_init(&this, "test");
    join_s(&this, ' ', (const string_t * const *)tmp);
    cr_assert_eq(0, 0);
    join_s(NULL, ' ', NULL);
    join_s(&this, ' ', NULL);
}
