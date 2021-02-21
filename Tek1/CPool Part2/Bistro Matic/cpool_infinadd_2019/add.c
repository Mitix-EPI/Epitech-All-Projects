/*
** EPITECH PROJECT, 2019
** infinity add
** File description:
** Infinite addition between two strings
*/

char count_keep_pos(char *c, int i);

int my_strlen(char const *str);

char *my_revstr(char *str);

int end_add(char *str1, char *str2, char *res, char keep)
{
    int i = my_strlen(res);

    if (str2[i] != '\0' && str2[i] != '-') {
        for (i = i ; str2[i] != '\0' && str2[i] != '-' ; i += 1) {
            res[i] = (str2[i] - '0') + keep;
            keep = count_keep_pos(res, i);
            res[i] = res[i] + '0';
        }
    } else {
        for (i = i ; str1[i] != '\0' && str1[i] != '-' ; i += 1) {
            res[i] = (str1[i] - '0') + keep;
            keep = count_keep_pos(res, i);
            res[i] = res[i] + '0';
        }
    }
    if (keep == 1) {
        res[i] = keep + '0';
        i += 1;
    }
    return (i);
}

char *add_all(char *str1, char *str2, char *res)
{
    int i = 0;
    char keep = 0;
    int nb;

    for (i = 0 ; str1[i] != '\0' && str2[i] != '\0' ; i += 1) {
        if (str1[i] == '-' || str2[i] == '-')
            break;
        res[i] = str1[i] + str2[i] + keep - 96;
        keep = count_keep_pos(res, i);
        res[i] = res[i] + '0';
    }
    nb = i;
    i = end_add(str1, str2, res, keep);
    if (str1[nb] == '-' || str2[nb] == '-')
        res[i] = '-';
    return (my_revstr(res));
}