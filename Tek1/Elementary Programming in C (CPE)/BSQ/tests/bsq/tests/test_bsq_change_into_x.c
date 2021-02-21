/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** test_bsq_change_into_x
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>

char *bsq_reader(char *map);

Test(bsq_reader, return_a_simple_point)
{
    cr_redirect_stdout();
    bsq_reader("tests/text.txt");
    cr_assert_stdout_eq_str(".");
}

Test(bsq_reader, return_2_lines_of_points)
{
    cr_redirect_stdout();
    bsq_reader("tests/text2.txt");
    cr_assert_stdout_eq_str("...\n...\n...");
}