/*
** EPITECH PROJECT, 2019
** multiplication
** File description:
** Multiplication test
*/

#include <stdlib.h>
#include <string.h>
#include "../include/bistromatic.h"

void check_bugs(char *str1, char *str2, char *res, int signe)
{
    my_revstr(res);
    if (signe == 2) {
        res[my_strlen(res)] = '-';
        res[my_strlen(res) + 1] = '\0';
    }
    if (res[my_strlen(res) - 1] == '0')
        res[my_strlen(res) - 1] = '\0';
    if (str1[0] == '0' && str1[1] == '\0')
        res[1] = '\0';
    if (str2[0] == '0' && str2[1] == '\0')
        res[1] = '\0';
    my_revstr(res);
}

char *my_memset(char *dest, int val, int len)
{
    for (int x = 0; len-- > 0; x++)
        dest[x] = val;
    return (dest);
}

void my_double_revstr(char *n1, char *n2)
{
    my_revstr(n1);
    my_revstr(n2);
}

int check_res_mult_neg(char *str1, char *str2, int *i, int *j)
{
    my_double_revstr(str1, str2);
    if (str1[my_strlen(str1) - 1] == '-' && str2[my_strlen(str2) - 1] != '-') {
        str1[my_strlen(str1) - 1] = '\0';
        *i -= 1;
        return (2);
    }
    if (str1[my_strlen(str1) - 1] != '-' && str2[my_strlen(str2) - 1] == '-') {
        str2[my_strlen(str2) - 1] = '\0';
        *j -= 1;
        return (2);
    }
    if (str1[my_strlen(str1) - 1] == '-' && str2[my_strlen(str2) - 1] == '-') {
        str1[my_strlen(str1) - 1] = '\0';
        str2[my_strlen(str2) - 1] = '\0';
        *i -= 1;
        *j -= 1;
        return (1);
    }
    return (0);
}

char *mult(char *str1, char *str2)
{
    char *res;
    int calc;
    int i = my_strlen(str1);
    int j = my_strlen(str2);
    int signe = check_res_mult_neg(str1, str2, &i, &j);

    my_double_revstr(str1, str2);
    res = malloc(sizeof(char) * (i * j + 1));
    my_memset(res, '0', i + j);
    res[i + j] = 0;
    for (i = i - 1; i >= 0; i--)
        for (j = j - 1; j >= 0; j--){
            calc = (str1[i] - '0') * (str2[j] - '0');
            res[i + j] += ((res[i + j + 1] + calc - '0') / 10);
            res[i + j + 1] = ((res[i + j + 1] + calc - '0') % 10) + '0';
        }
    check_bugs(str1, str2, res, signe);
    return (res);
}