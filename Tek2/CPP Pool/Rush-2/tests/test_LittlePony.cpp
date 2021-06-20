/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_LittlePony
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../LittlePony.hpp"

Test(LittlePony, should_create_pony)
{
    LittlePony pony("Rose");
    std::string resultName = pony.getName();
    std::string resultType = pony.getType();

    cr_assert_eq(resultName, "Rose");
    cr_assert_eq(resultType, "Little Pony");
}

Test(LittlePony, should_be_took)
{
    LittlePony pony("Rose");

    cr_redirect_stdout();
    pony.isTaken();
    cr_assert_stdout_eq_str("yo man\n");
}

Test(LittlePony, should_display_operator)
{
    LittlePony pony("Titouane");

    cr_redirect_stdout();
    std::cout << pony;
    cr_assert_stdout_eq_str("I'm Titouane and I'm a little pony!\n");
}