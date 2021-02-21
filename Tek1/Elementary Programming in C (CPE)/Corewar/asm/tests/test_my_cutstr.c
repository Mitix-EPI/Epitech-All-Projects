/*
** EPITECH PROJECT, 2020
** test my_cutstr
** File description:
** units tests for function of my_cutstr
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(my_cutstr, should_remove_spaces_tabs)
{
    char str[] = "Hi how are you ?\n";
    char str1[] = "Hola !    ";
    char str2[] = "Bonjour ! \n";
    char str3[] = "Halo";

    my_cutstr(str);
    my_cutstr(str1);
    my_cutstr(str2);
    my_cutstr(str3);
    cr_assert_str_eq(str, "Hi how are you ?");
    cr_assert_str_eq(str1, "Hola !");
    cr_assert_str_eq(str2, "Bonjour !");
    cr_assert_str_eq(str3, "Halo");
}