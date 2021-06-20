/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** test_ex00
*/

#include <criterion/criterion.h>
#include "../ex00.hpp"

Test(min, should_return_smallest)
{
    int res1 = ::min(2, 3);
    cr_assert_eq(res1, 2);

    int res2 = ::min(3, 2);
    cr_assert_eq(res2, 2);

    int res3 = ::min(3, 3);
    cr_assert_eq(res3, 3);
}

Test(max, should_return_greatest)
{
    int res1 = ::max(2, 3);
    cr_assert_eq(res1, 3);

    int res2 = ::max(3, 2);
    cr_assert_eq(res2, 3);

    int res3 = ::max(3, 3);
    cr_assert_eq(res3, 3);
}

Test(add, should_return_sum)
{
    int res1 = ::add(2, 3);
    cr_assert_eq(res1, 5);

    int res2 = ::add(-3, 2);
    cr_assert_eq(res2, -1);

    float res3 = ::add(3.12, 3.13);
    cr_assert_eq(res3, 6.25);
}

Test(swap, should_return_swap)
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    cr_assert_eq(a, 3);
    cr_assert_eq(b, 2);

    ::swap(a, b);
    cr_assert_eq(a, 2);
    cr_assert_eq(b, 3);
}
