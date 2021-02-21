/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main for infinity add
*/

#include <stdlib.h>
#include "../include/bistromatic.h"

void error_too_many_arg(void);

void error_less_arg(void);

char *add_all(char *str1, char *str2, char *res);

char *substract_all(char *str1, char *str2, char *res);

int check_letter(char *str);

void error_have_letter(void);

int my_putstr(char const *str);

char *infin_add(char *str1, char *str2)
{
    int i = my_strlen(str1);
    int j = my_strlen(str2);
    char *res = malloc(sizeof(char) * (i + j));

    if (str1[0] == '-' && str2[0] != '-' || str1[0] != '-' && str2[0] == '-') {
        res = substract_all(str1, str2, res);
    } else {
        res = add_all(my_revstr(str1), my_revstr(str2), res);
    }
    return (res);
}