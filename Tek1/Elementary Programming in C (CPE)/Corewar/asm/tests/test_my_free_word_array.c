/*
** EPITECH PROJECT, 2020
** test my_free_word_array
** File description:
** units tests for functions in my_free_word_array
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(my_free_word_array, should_free_a_word_array)
{
    char **array = malloc(sizeof(char *) * (2 + 1));
    char *str = malloc(sizeof(char) * (1));
    char *str2 = malloc(sizeof(char) * (1));
    int ret = 0;

    array[0] = str;
    array[1] = str2;
    array[2] = NULL;
    my_free_word_array(array);
    cr_assert_eq(ret, 0);
}