/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>

int my_printf(char const *format, ...);

Test(my_printf, should_return_coucou)
{
    cr_redirect_stdout();
    my_printf("coucou");
    cr_assert_stdout_eq_str("coucou");
}

Test(my_printf, should_return_3)
{
    cr_redirect_stdout();
    my_printf("%d", 3);
    cr_assert_stdout_eq_str("3");
}

Test(my_printf, should_return_aa)
{
    char *slt = "a%a";

    cr_redirect_stdout();
    my_printf("a%%a");
    cr_assert_stdout_eq_str(slt);
}

Test(my_printf, should_return_slt)
{
    char *slt = "slt";

    cr_redirect_stdout();
    my_printf("%s", slt);
    cr_assert_stdout_eq_str("slt");
}

Test(my_printf, should_return_2)
{

    cr_redirect_stdout();
    my_printf("%i", 20);
    cr_assert_stdout_eq_str("20");
}

Test(my_printf, should_return_man)
{
    cr_assert_eq(my_printf("  %h  "), 0);}

Test(my_printf, should_return_r)
{
    cr_redirect_stdout();
    my_printf("%c", 'r');
    cr_assert_stdout_eq_str("r");
}

Test(my_printf, should_return_ptr)
{
    int p = 6;

    cr_assert_eq(my_printf("%p", p), 1);
}

Test(my_printf, should_return_hexa)
{
    int p = -16;

    cr_assert_eq(my_printf("%x", p), 1);
}

Test(my_printf, should_return_oct)
{
    int p = 16;

    cr_assert_eq(my_printf("%o", p), 1);
}

Test(my_printf, should_return_bin)
{
    int p = 16;

    cr_assert_eq(my_printf("%b", p), 1);
}

Test(my_printf, should_return_notneg)
{
    int p = 16;

    cr_assert_eq(my_printf("%u", p), 1);
}

Test(my_printf, should_return_arr)
{
    char *test[] = {"bit", 0};

    cr_assert_eq(my_printf("%a", test), 1);
}

Test(my_printf, should_return_neg11)
{
    int p = -11;

    cr_assert_eq(my_printf("%d", p), 1);
}

Test(my_printf, should_return_not_flag)
{
    cr_assert_eq(my_printf("%G"), 1);
}

Test(my_printf, should_return_pace)
{
    int p = 6;

    cr_assert_eq(my_printf("%        d", p), 1);
}

Test(my_printf, should_return_1_int_star)
{
    int *i = malloc(sizeof(i) * (2 + 1));

    i[0] = 67;
    i[1] = -5;
    i[2] = 0;
    cr_assert_eq(my_printf("%t", i), 1);
}

Test(my_printf, should_return_hexa_maj)
{
    int p = -16;

    cr_assert_eq(my_printf("%X", p), 1);
}

Test(my_printf, should_return_coucou_rainbow)
{
    cr_assert_eq(my_printf("%r", "coucoudiedeide"), 1);
}