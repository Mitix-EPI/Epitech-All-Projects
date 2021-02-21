/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tests_my_sokoban
*/

#include <criterion/criterion.h>
//#include "../include/my.h"

char **my_str_to_word_array(char const *);

Test(my_str_to_word_array, should_return_AAA_NULL)
{
    char message[] = "AAA";
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "AAA");
    cr_assert_null(result[1]);
}

Test(my_str_to_word_array, should_return_word_array)
{
    char *message = malloc(sizeof(char) * 3);

    message[0] = 'A';
    message[1] = 127;
    message[2] = '\0';

    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_cool)
{
    char *message = malloc(sizeof(char) * 3);

    message[0] = 'A';
    message[1] = 6;
    message[2] = '\0';

    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_super)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = 129;
    message[1] = 'r';
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_super2)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = 50;
    message[1] = 50;
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_superdz)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = 'r';
    message[1] = 'r';
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_supers)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = '7';
    message[1] = '7';
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_super5)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = 1;
    message[1] = 1;
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_supe4r)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = 129;
    message[1] = 129;
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_supergalere)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = '\0';
    message[1] = 'r';
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}

Test(my_str_to_word_array, should_return_supefyr)
{
    char *message = malloc(sizeof(char) * 4);

    message[0] = 45;
    message[1] = '\0';
    message[2] = '\0';
    char **result = my_str_to_word_array(message);
    cr_assert_not_null(result);
    free(message);
}