/*
** EPITECH PROJECT, 2019
** test_my_strcmp.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, return_value)
{
    char s1[8] = {'0'};
    char s2[8] = {'0'};

    strcpy(s1, "Bonj");
    strcpy(s2, "Bonsoir");
    cr_assert_eq(my_strcmp(s1, s2), -9);
}
