/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include "../../include/my.h"

Test(my_strcmp, return_0)
{
    cr_assert_eq(my_strcmp("Coucou", "Coucou"), 0);
}

Test(my_strcmp, return_other_than_0)
{
    cr_assert_neq(my_strcmp("Coucou", "toi"), 0);
}

Test(my_strcmp, last_check)
{
    cr_assert_neq(my_strcmp("Cou", "Couc"), 0);
}