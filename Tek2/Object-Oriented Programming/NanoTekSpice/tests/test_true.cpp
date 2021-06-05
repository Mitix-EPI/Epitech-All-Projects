/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-tekspice-cyril.grosjean
** File description:
** test_true
*/

#include "../include/Component.hpp"
#include "../include/Components/C_True.hpp"
#include <criterion/criterion.h>

Test(init, should_init_correctly)
{
    C_True c_true;

    cr_assert_eq(c_true.getType(), "true");
}
