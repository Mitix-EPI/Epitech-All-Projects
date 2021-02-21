/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(generate_random, return1)
{
    cr_assert_eq(generate_random(1, 1), 1);
}