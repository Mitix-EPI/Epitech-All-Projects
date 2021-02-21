/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** return 0
*/

#include <stdlib.h>

int my_str_isnum(char const *str);

int my_putstr_errors(char const *str);

int my_putstr(char const *str);

int my_strlen(char const *str);

char *my_revstr(char *str);

int complete_res(char *revstr1, char *revstr2, char *res, int i, int retenue)
{
    int calcul_cache;
    int j;
    int calcul;

    if (revstr1[i] != '\0') {
        for (j = i; revstr1[j] != '\0'; j++) {
            calcul = ((revstr1[j] - '0') + retenue);
            if (calcul >= 10) {
                calcul -= 10;
                retenue = 1;
            }
            else
                retenue = 0;
            res[j] = calcul + '0';
        }
    }
    if (revstr2[i] != '\0') {
        for (j = i; revstr2[j] != '\0'; j++) {
            calcul = ((revstr2[j] - '0') + retenue);
            if (calcul >= 10) {
                calcul -= 10;
                retenue = 1;
            }
            else
                retenue = 0;
            res[j] = calcul + '0';
        }
    }
    if (retenue == 1)
        res[j] = '1';
    res = my_revstr(res);
    my_putstr(res);
}

int calcul(char *str1, char *str2, char *res)
{
    char *revstr1 = my_revstr(str1);
    char *revstr2 = my_revstr(str2);
    int calcul_cache = 0;
    int retenue = 0;
    int i = 0;

    for (i = 0; revstr1[i] != '\0' && revstr2[i] != '\0'; i++) {
        calcul_cache = (revstr1[i] - '0') + (revstr2[i] - '0') + retenue;
        retenue = 0;
        if (calcul_cache >= 10) {
            calcul_cache -= 10;
            retenue = 1;
        }
        res[i] = (calcul_cache + '0');
    }
    if (revstr1[i] == '\0' || revstr2[i] == '\0') {
        if (my_strlen(str1) == my_strlen(str2))
            if (retenue == 1) {
                res[i] = '1';
                res = my_revstr(res);
                my_putstr(res);
                return (0);
            }
        complete_res(revstr1, revstr2, res, i, retenue);
    }
    return (0);
}

void infin_add(char *str1, char *str2)
{
    char *res;

    res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)) + 1);
    calcul(str1, str2, res);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        my_putstr_errors("Error number of arguments");
        return (0);
    }
    if (my_str_isnum(argv[1]) && my_str_isnum(argv[2])) {
        infin_add(argv[1], argv[2]);
        return (0);
    }
    else {
        my_putstr_errors("Please enter only numbers");
        return (0);
    }
}
