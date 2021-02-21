/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_parse_commands
*/

#include "../include/my.h"

int count_args_co(char *str)
{
    int i = 0;
    int count = 0;

    for (; str[i] && (str[i] == ' ' || str[i] == 9); i++);
    for (; str[i]; i++) {
        if ((str[i] != 9 && str[i] != ' ') &&
        (str[i + 1] == 9 || str[i + 1] == ' ' || str[i + 1] == 0))
            count++;
    }
    return (count);
}

int count_nb_char_co(char *str, char c, int *i)
{
    int count = 0;

    for (; str[*i] != c; *i += 1)
        count += 1;
    *i += 2;
    return (count);
}

char **my_parse_commands(char *str, char c)
{
    int count_arg = count_args_co(str);
    char **tmp = malloc(sizeof(char *) * (count_arg + 1));
    int x = 0;

    tmp[count_arg] = NULL;
    for (int j = 0, a = 0; j < count_arg; j++, x++) {
        a = 0;
        tmp[j] = malloc(sizeof(tmp[j]) * (1000 + 1));
        for (;str[x] == c || str[x] == 9; x++);
        for (a = 0; str[x] != c && str[x] != 0; x++, a++)
            if (str[x] != ' ' && str[x] != 9)
                tmp[j][a] = str[x];
            else
                a--;
        tmp[j][a] = 0;
    }
    return (tmp);
}

char **return_good_env(char **env)
{
    char **return_array;
    int i = 0;

    for (; env[i] != NULL; i++)
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H')
            break;
    return_array = my_parse_string(env[i] + 5, ':');
    return (return_array);
}