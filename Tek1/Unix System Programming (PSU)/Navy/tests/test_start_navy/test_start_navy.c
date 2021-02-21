/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_start_navy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main_navy(int ac, char **av);

Test(main_navy, return_84)
{
    cr_assert_eq(main_navy(1, NULL), 84);
}