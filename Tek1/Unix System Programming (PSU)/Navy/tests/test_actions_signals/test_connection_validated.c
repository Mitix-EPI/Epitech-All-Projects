/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_connection_validated
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(connection_validated, print_successfully_connected)
{
    cr_redirect_stdout();
    connection_validated(0);
    cr_assert_stdout_eq_str("successfully connected\n");
}

Test(connection_ennemy_validated, print_ennemy_connected)
{
    struct siginfo_t *siginfo = NULL;
    void *context = NULL;

    cr_redirect_stdout();
    connection_ennemy_validated(0, &siginfo, context);
    cr_assert_stdout_eq_str("enemy connected\n");
}

Test(catch_siguser1, return_null_in_output)
{
    struct siginfo_t *siginfo;
    void *context = NULL;

    cr_redirect_stdout();
    catch_siguser1(0, &siginfo, context);
}

Test(catch_siguser2, return_null_in_output2)
{
    struct siginfo_t *siginfo = NULL;
    void *context = NULL;

    cr_redirect_stdout();
    catch_siguser2(0, &siginfo, context);
}