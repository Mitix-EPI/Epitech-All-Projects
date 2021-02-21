/*
** EPITECH PROJECT, 2019
** my_strupcase.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strupcase(char *str);

Test(my_strupcase, return_value)
{
    char str[35] = {'0'};

    strcpy(str, "j'aimerai bien CETTE phrase en maj");
    cr_assert_str_eq(my_strupcase(str), "J'AIMERAI BIEN CETTE PHRASE EN MAJ");
}
