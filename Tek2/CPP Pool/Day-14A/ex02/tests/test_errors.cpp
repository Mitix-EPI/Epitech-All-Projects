/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14A-alexandre.juan
** File description:
** test_errors
*/

#include "../Errors.hpp"
#include <criterion/criterion.h>

Test(NasaErrors, test_constructor)
{
    NasaError err("message");
    std::string test = err.getComponent();

    cr_assert_str_eq(err.what(), "message");
    cr_assert_eq(test, std::string("Unknown"));

    NasaError err2("message2", "component");
    cr_assert_str_eq(err2.what(), "message2");
    cr_assert_eq(err2.getComponent(), std::string("component"));
}

Test(MissionCriticalError, test_constructor)
{
    MissionCriticalError err("message", "component");
    std::string test = err.getComponent();

    cr_assert_str_eq(err.what(), "message");
    cr_assert_eq(test, std::string("component"));
}

Test(LifeCriticalError, test_constructor)
{
    LifeCriticalError err("message", "component");
    std::string test = err.getComponent();

    cr_assert_str_eq(err.what(), "message");
    cr_assert_eq(test, std::string("component"));
}

Test(UserError, test_constructor)
{
    UserError err("message", "component");
    std::string test = err.getComponent();

    cr_assert_str_eq(err.what(), "message");
    cr_assert_eq(test, std::string("component"));
}

Test(CommunicationError, test_constructor)
{
    CommunicationError err("message");
    std::string test = err.getComponent();

    cr_assert_str_eq(err.what(), "message");
    cr_assert_eq(test, std::string("CommunicationDevice"));
}
