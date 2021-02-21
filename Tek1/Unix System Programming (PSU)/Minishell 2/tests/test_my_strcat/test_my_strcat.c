/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_strcat
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

char *my_strcat(char *dest, char const *src);

Test(my_strcat_, should_concats_2_strings)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    char *tmp3 = NULL;

    tmp1 = my_strcat("Coucou", "toi");
    cr_assert_str_eq(tmp1, "Coucou/toi");
    free(tmp1);
}
