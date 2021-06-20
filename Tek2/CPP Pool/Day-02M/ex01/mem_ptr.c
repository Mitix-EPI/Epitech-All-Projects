/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02M-alexandre.juan
** File description:
** mem_ptr
*/

#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int sum = strlen(str1) + strlen(str2);
    *res = malloc(sizeof(char) * (sum + 1));
    memset(*res, '\0', sum);
    strcat(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    int sum = strlen(str_op->str1) + strlen(str_op->str2);
    str_op->res = malloc(sizeof(char) * (sum + 1));
    memset(str_op->res, '\0', sum);
    strcat(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);
}
