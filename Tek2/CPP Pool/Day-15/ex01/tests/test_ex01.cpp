/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** test_ex00
*/

#include <criterion/criterion.h>
#include "../ex01.hpp"
#include <string>

Test(compare, should_compare_correctly)
{
    std::string        v1 = "tricheur";
    std::string        v2 = "navet_m";
    std::string        v3 = "sale con";
    std::string const    v4 = "tricheur";

    int res = compare(v1, v4);
    cr_assert_eq(res, 0);

    res = compare(v1, v2);
    cr_assert_eq(res, 1);

    res = compare(v2, v3);
    cr_assert_eq(res, -1);
}

Test(compare, should_compare_const_chars_correctly)
{
    const char    s1[8] = "chaineZ";
    const char    s2[10] = "chaineA42";
    const char    *s3 = "42";
    const char    *s4 = "lulz";
    const char    *s5 = "lulz";

    int res = compare<const char *>(s1, s2);
    cr_assert_eq(res, 1);

    res = compare(s3, s4);
    cr_assert_eq(res, -1);

    res = compare(s4, s5);
    cr_assert_eq(res, 0);
}
