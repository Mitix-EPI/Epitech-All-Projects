/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_Teddy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Teddy.hpp"

Test(Teddy, should_create_teddy)
{
    Teddy ted("Bob");
    std::string resultName = ted.getName();
    std::string resultType = ted.getType();

    cr_assert_eq(resultName, "Bob");
    cr_assert_eq(resultType, "Teddy");
}

Test(Teddy, should_be_took)
{
    Teddy ted("Bob");

    cr_redirect_stdout();
    ted.isTaken();
    cr_assert_stdout_eq_str("gra hu\n");
}

Test(Teddy, should_display_operator)
{
    Teddy ted("Bob");

    cr_redirect_stdout();
    std::cout << ted;
    cr_assert_stdout_eq_str("I'm Bob and I'm a teddy bear!\n");
}