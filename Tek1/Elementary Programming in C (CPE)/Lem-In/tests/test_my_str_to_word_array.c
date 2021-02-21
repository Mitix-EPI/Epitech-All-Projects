/*
** EPITECH PROJECT, 2020
** test my_str_to_word_array
** File description:
** units tests for str_to_word_array
*/

#include "lemin.h"
#include <criterion/criterion.h>

int jump_index(int index, char *str, char split);

Test(my_str_to_word_array, should_return_word)
{
    char str[26] = "Bonjour\nMy name is\nRoger.";
    char **word = my_str_to_word_array('\n', str);

    cr_assert_str_eq(word[0], "Bonjour");
    cr_assert_str_eq(word[1], "My name is");
    cr_assert_str_eq(word[2], "Roger.");
    cr_assert_null(word[3]);
}

Test(jump_index, should_return_index)
{
    int ret = jump_index(0, "\0", '\n');

    cr_assert_eq(ret, 0);
}