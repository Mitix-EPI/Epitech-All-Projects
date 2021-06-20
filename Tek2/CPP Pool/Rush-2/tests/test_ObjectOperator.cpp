/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_ObjectOperator
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Teddy.hpp"

Test(Teddy, should_display_name_and_type_object)
{
    Object *ted = new Teddy("Bobo");

    cr_redirect_stdout();
    std::cout << *ted;
    cr_assert_stdout_eq_str("I'm Bobo and I am a Teddy\n");
}