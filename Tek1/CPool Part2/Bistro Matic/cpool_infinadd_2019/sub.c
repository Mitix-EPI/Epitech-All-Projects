/*
** EPITECH PROJECT, 2019
** substract
** File description:
** Sub a number
*/

#include <stdlib.h>

char *my_revstr(char *str);

int my_strlen(char const *str);

char count_keep_neg(char *c, int i);

int get_bigger_nb(char *str1, char *str2);

void end_sub(char *str1, char *str2, char *res, char keep)
{
    int i = my_strlen(res);

    if (str2[i] != '\0' && str2[i] != '-') {
        for (i = i ; str2[i] != '\0' && str2[i] != '-' ; i += 1) {
            res[i] = (str2[i] - '0') - keep;
            keep = count_keep_neg(res, i);
            res[i] += '0';
        }
    } else {
        for (i = i ; str1[i] != '\0' && str1[i] != '-' ; i += 1) {
            res[i] = (str1[i] - '0') - keep;
            keep = count_keep_neg(res, i);
            res[i] += '0';
        }
    }
}

char *substract(char *str1, char *str2, char *res)
{
    int i = 0;
    int keep = 0;

    for (i = 0 ; str1[i] != '\0' && str2[i] != '\0' ; i += 1) {
        if (str1[i] == '-' || str2[i] == '-')
            break;
        res[i] = (str1[i] - str2[i]) - keep;
        keep = count_keep_neg(res, i);
        res[i] += '0';
    }
    end_sub(str1, str2, res, keep);
    return (res);
}

char *set_correctchar(char *res)
{
    int i = 0;
    int a = 0;
    char *str = malloc(sizeof(res));

    my_revstr(res);
    if (res[0] == '-') {
        str[0] = '-';
        i += 1;
        a += 1;
    }
    while (res[i] == '0')
        i += 1;
    for (i = i ; res[i] != '\0' ; i += 1) {
        str[a] = res[i];
        a += 1;
    }
    return (str);
}

char *substract_all(char *str1, char *str2, char *res)
{
    int r = get_bigger_nb(str1, str2);
    char *swap = malloc(sizeof(str1));
    int i;

    if (r == 0) {
        res = substract(my_revstr(str1), my_revstr(str2), res);
    } else if (r == 1) {
        swap = str1;
        str1 = malloc(sizeof(str2));
        str1 = str2;
        str2 = swap;
        res = substract(my_revstr(str1), my_revstr(str2), res);
    } else
        return ("0\0");
    my_revstr(str1);
    i = my_strlen(res);
    if (str1[0] == '-')
        res[i] = '-';
    return (set_correctchar(res));
}