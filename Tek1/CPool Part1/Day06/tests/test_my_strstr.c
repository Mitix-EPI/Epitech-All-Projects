/*
** EPITECH PROJECT, 2019
** test_my_strstr.c
** File description:
** test function strstr.c
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, return_finding_characters)
{
    char str1[6] = {'0'};
    char str2[6] = {'0'};

    strcpy(str1, "Salut");
    strcpy(str2, "lu");
    cr_assert_str_eq(my_strstr(str1, str2), "lut");
}
