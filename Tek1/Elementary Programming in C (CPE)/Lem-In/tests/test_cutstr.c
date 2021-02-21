/*
** EPITECH PROJECT, 2020
** test cutstr
** File description:
** units tests for cutstr
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(cutstr, should_change_str)
{
    char str[20] = "Bonjour    # Coucou";
    char str2[21] = "Bonjour    \n#Coucou";
    char str3[4] = "6-2";
    char str4[4] = "6 2";

    cutstr(str);
    cutstr(str2);
    cutstr(str3);
    cutstr(str4);
    cr_assert_str_eq(str, "Bonjour");
    cr_assert_str_eq(str2, "Bonjour");
    cr_assert_str_eq(str3, "6-2");
    cr_assert_str_eq(str4, "6 2");
}