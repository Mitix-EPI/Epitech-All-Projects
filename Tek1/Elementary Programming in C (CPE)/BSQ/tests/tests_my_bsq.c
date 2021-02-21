/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** tests_my_bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>

int main_bsq(int ac, char **av);

Test(main_bsq, should_return_0)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1] = "tests/bsq/maps/mouli_maps/intermediate_map_200_200\0";
    cr_assert_eq(main_bsq(2, av), 0);
    free(av);
}

Test(main_bsq, should_return_84)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (7 + 1));
    av[1] = "../txt\0";
    cr_assert_eq(main_bsq(2, av), 84);
    free(av);
}

Test(main_bsq, should_return_84_cause_not_enough_args)
{
    int ac = 3;
    char **av = malloc(sizeof(av) * (3 + 1));

    av[0] = malloc(sizeof(char *) * (7 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char *) * (3 + 1));
    av[1] = "fck\0";
    av[2] = malloc(sizeof(char *) * (4 + 1));
    av[2] = "you\0";
    cr_assert_eq(main_bsq(ac, av), 84);
    free(av);
}

Test(main_bsq, should_return_84_cause_not_good_line)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1] = "tests/bsq/tests/text.txt\0";
    cr_assert_eq(main_bsq(2, av), 84);
    free(av);
}

Test(main_bsq, should_return_O_but_letters_on_start)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1] = "tests/bsq/tests/text3.txt\0";
    cr_assert_eq(main_bsq(2, av), 0);
    free(av);
}

Test(main_bsq, should_return_84_empty_file)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1] = "tests/bsq/tests/empty.txt\0";
    cr_assert_eq(main_bsq(2, av), 84);
    free(av);
}

Test(main_bsq, should_return_84_folder)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1] = "tests/bsq/tests/\0";
    cr_assert_eq(main_bsq(2, av), 84);
    free(av);
}

Test(main_bsq, should_return_help)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (2 + 1));
    av[1] = "-h\0";
    cr_assert_eq(main_bsq(2, av), 0);
    free(av);
}

Test(main_bsq, should_return_error_help)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1] = "-g\0";
    cr_assert_eq(main_bsq(3, av), 84);
    free(av);
}

Test(main_bsq, should_return_84_execute_only)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (28 + 1));
    av[1] = "tests/bsq/txt\0";
    cr_assert_eq(main_bsq(2, av), 84);
    free(av);
}

Test(main_bsq, should_return_help_2)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1][0] = 'h';
    av[1][1] = 'h';
    cr_assert_eq(main_bsq(3, av), 84);
    free(av);
}

Test(main_bsq, should_return_good_help)
{
    char **av = malloc(sizeof(av) * (2 + 1));

    av[0] = malloc(sizeof(av[0]) * (5 + 1));
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(av[1]) * (71 + 1));
    av[1][0] = 'h';
    av[1][1] = 'h';
    cr_assert_eq(main_bsq(2, av), 0);
    free(av);
}