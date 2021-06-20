/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** test_c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main(int ac, char **av);

Test(my_put_nbr, should_display_positive_number)
{
    cr_redirect_stdout();
    main(0, NULL);
    cr_assert_stdout_eq_str("z\n");
}
