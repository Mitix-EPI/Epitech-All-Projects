/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** test_aenemy
*/

#include <criterion/criterion.h>
#include "../AEnemy.hpp"

Test(AEnemy, should_decrease_hp)
{
    AEnemy tmp(100, "Méchant");

    tmp.takeDamage(60);
    cr_assert_eq(tmp.getHP(), 40);
    // cr_assert_str_eq(tmp.getType(), new std::string("Méchant"));
}
