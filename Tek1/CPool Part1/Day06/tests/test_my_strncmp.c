/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** test the function strncmp
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, return_substrack)
{
    char str1[9] = {'0'};
    char str2[9] = {'0'};
    int n = 3;

    strcpy(str1, "z");
    strcpy(str2, "a");
    printf("%d\n", my_strncmp(str1, str2, n));
    printf("%d\n", strncmp(str1, str2, n));
    cr_assert_eq(my_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
