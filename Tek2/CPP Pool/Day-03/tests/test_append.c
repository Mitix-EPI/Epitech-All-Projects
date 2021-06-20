/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_append
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(append_c, should_return_mattislittot)
{
    string_t string;

    string.str = strdup("Mattis");
    append_c(&string, "Littot");
    cr_assert_str_eq(string.str, "MattisLittot");
    free(string.str);
}

Test(append_c, should_add_juanito)
{
    string_t string;

    string.str = NULL;
    append_c(&string, "Juanito");
    cr_assert_str_eq(string.str, "Juanito");
    free(string.str);
}

Test(append_s, should_return_SebTaliban)
{
    string_t string1;
    string_t string2;

    string1.str = strdup("Seb");
    string2.str = strdup("Taliban");
    append_s(&string1, &string2);
    cr_assert_str_eq(string1.str, "SebTaliban");
    free(string1.str);
    free(string2.str);
}

Test(append_s, should_return_Damien)
{
    string_t string1;
    string_t string2;

    string1.str = NULL;
    string2.str = strdup("Damien");
    append_s(&string1, &string2);
    cr_assert_str_eq(string1.str, "Damien");
    free(string1.str);
    free(string2.str);
}