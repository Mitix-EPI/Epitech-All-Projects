/*
** EPITECH PROJECT, 2019
** My errors
** File description:
** Display error messages
*/

#include <unistd.h>

int check_letter(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' && str[i] != '-' || str[i] > '9') {
            return (0);
        }
        i += 1;
    }
    return (1);
}

void error_too_many_arg(void)
{
    char str[19] = "Too many arguments";
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i += 1;
    }
    write(2, "\n", 1);
}

void error_less_arg(void)
{
    char str[25] = "Please enter 2 arguments";
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i += 1;
    }
    write(2, "\n", 1);
}

void error_have_letter(void)
{
    char str[26] = "Please enter only numbers";
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i += 1;
    }
    write(2, "\n", 1);
}