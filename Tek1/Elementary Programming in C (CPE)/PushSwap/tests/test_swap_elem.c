/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** test_swap_elem
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(main_pushswap, return0)
{
    char *args[4] = {"./pushswap", "5", "19", "24"};
    int size = 4;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_1)
{
    char *args[4] = {"./pushswap", "24", "19", "3"};
    int size = 4;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_2)
{
    char *args[6] = {"./pushswap", "24", "19", "3", "9", "1"};
    int size = 6;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_3)
{
    char *args[6] = {"./pushswap", "-24", "19", "3", "-9", "1"};
    int size = 6;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_4)
{
    char *args[4] = {"./pushswap", "2", "1", "246835"};
    int size = 4;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_5)
{
    char *args[13] = {"./pushswap", "10", "9", "8", "7", "6",
    "5", "4", "3", "2", "1", "0", "11"};
    int size = 13;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_6)
{
    char *args[2] = {"./pushswap", "e"};
    int size = 2;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}

Test(main_pushswap, return0_8)
{
    char *args[2] = {"./pushswap", "--2"};
    int size = 2;
    int ret = main_pushswap(size, args);
    cr_assert_eq(ret, 0);
}