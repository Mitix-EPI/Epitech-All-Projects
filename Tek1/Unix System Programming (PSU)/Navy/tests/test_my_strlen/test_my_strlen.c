/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>

int my_strlen(char const *str);

int my_strlen2(char const *str);

Test(my_strlen2, test_on_empty_string)
{
    int result = my_strlen2("");
    cr_assert_eq(result, 0);
}

Test(my_strlen, test_on_normal_string)
{
    int result = my_strlen("Hello\n");
    cr_assert_eq(result, 5);
}

Test(my_strlen2, test_on_full_sentence)
{
    int result = my_strlen2("Hello World!");
    cr_assert_eq(result, 12);
}

Test(my_strlen2, test_on_potentially_broken_strings)
{
    int result = my_strlen2("Hello+-*/\nworld");
    cr_assert_eq(result, 15);
}
