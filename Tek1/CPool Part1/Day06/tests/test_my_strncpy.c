/*
** EPITECH PROJECT, 2019
** test_my_strncpy.c
** File description:
** test fonction
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char my_dest[11] = {'O'};
    char src[11] = {'0'};

    strcpy(src, "HelloWorld");
    cr_assert_str_eq(my_strncpy(my_dest, src, 5), "Hello");
}
