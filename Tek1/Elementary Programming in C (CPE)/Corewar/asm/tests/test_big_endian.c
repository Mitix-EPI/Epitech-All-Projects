/*
** EPITECH PROJECT, 2020
** test big_endian
** File description:
** unit tests for big endian
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(little_to_big, should_return_number)
{
    int ret = little_to_big(8);

    cr_assert_eq(ret, 134217728);
}