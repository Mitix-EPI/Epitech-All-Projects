/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_start
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(siginhandler, display_prompt)
{
    siginhandler(0);
}

Test(siginhandler, display_prompt_and_n)
{
    siginhandler(666);
}