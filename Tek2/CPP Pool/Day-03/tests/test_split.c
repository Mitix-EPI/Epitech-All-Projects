/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** test_split
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../string.h"

Test(split_c, should_return_splitted_array)
{
    string_t this;
    this.str = strdup("Bonjour,Monsieur,Karim");
    char **res = split_c(&this, ',');
    cr_assert_str_eq(res[0], "Bonjour");
    cr_assert_str_eq(res[1], "Monsieur");
    cr_assert_str_eq(res[2], "Karim");
    free(this.str);
    free(res[0]);
    free(res[1]);
    free(res[2]);
    free(res);
}

Test(split_s, should_return_splitted_structed_array)
{
    string_t this;
    this.str = strdup("Bonjour,Monsieur,Karim");
    string_t **res = split_s(&this, ',');
    cr_assert_str_eq(res[0]->str, "Bonjour");
    cr_assert_str_eq(res[1]->str, "Monsieur");
    cr_assert_str_eq(res[2]->str, "Karim");
    free(this.str);
    free(res[0]);
    free(res[1]);
    free(res[2]);
    free(res);
}
