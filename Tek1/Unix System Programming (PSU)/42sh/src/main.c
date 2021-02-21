/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Main of minishell2
*/

#include "minishell2.h"
#include "initialization.h"

int    main(int ac, char **argv, char **env)
{
    int enable_ncurse = 1;

    if (ac > 1 && !my_strcmp(argv[1], "-f"))
        enable_ncurse = 0;
    int ret = initialize(env, enable_ncurse);

    return (ret);
}
