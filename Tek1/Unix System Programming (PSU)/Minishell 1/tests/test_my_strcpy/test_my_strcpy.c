/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_strcpy
*/

#include <criterion/criterion.h>

char *my_strcpy (char *dest, char const *src);

Test(my_strcpy, should_return_string_Oui_from_src_string)
{
    char src[] = " Oui ";
    char dest[] = "";
    char *result = my_strcpy(dest, src);
    cr_assert_eq(result, dest);
}

Test(my_strcpy, should_find_empty_string_in_src)
{
    char src[] = "";
    char dest[] = "";
    char *result = my_strcpy (dest, src);
    cr_assert_eq (result, dest);
}
