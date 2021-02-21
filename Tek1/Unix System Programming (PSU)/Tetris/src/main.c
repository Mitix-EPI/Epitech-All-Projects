/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main
*/

#include "../include/my.h"

static struct option long_options[] = {
    {"--level=", required_argument, NULL, 'L'},
    {"--key-left=", required_argument, NULL, 'l'},
    {"--key-right=", required_argument, NULL, 'r'},
    {"--key-turn=", required_argument, NULL, 't'},
    {"--key-drop=", required_argument, NULL, 'd'},
    {"--key-quit=", required_argument, NULL, 'q'},
    {"--key-pause=", required_argument, NULL, 'p'},
    {"--without-next=", no_argument, NULL, 'w'},
    {"--debug=", no_argument, NULL, 'D'},
    {"--map-size=", required_argument, NULL, 0},
    {0, 0, 0, 0}
};

int want_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return (1);
    return (0);
}

int insane_loop(char *str1)
{
    for (int i = 0; i < 10; i++) {
        if (my_strncmp(str1, long_options[i].name, \
        my_strlen(long_options[i].name)) == 0) {
            return (1);
        }
    }
    return (0);
}

int insane_loop2(char *str1)
{
    for (int i = 0; i < 9; i++) {
        if (my_strcmp(str1, "-L") == 0 || my_strcmp(str1, "-l") == 0
        || my_strcmp(str1, "-r") == 0 || my_strcmp(str1, "-d") == 0
        || my_strcmp(str1, "-t") == 0 || my_strcmp(str1, "-q") == 0
        || my_strcmp(str1, "-p") == 0 || my_strcmp(str1, "-w") == 0
        || my_strcmp(str1, "-D") == 0)
            return (1);
    }
    return (0);
}

int check_flags(int ac, char **av)
{
    char *str = NULL;

    for (int i = 1; i < ac; i++) {
        if (insane_loop(av[i]) == 0 && insane_loop2(av[i]) == 0)
            if (av[i - 1][0] != '-')
                return (84);
    }
    for (int i = 1; i < ac; i++) {
        str = my_revstr(my_strdup(av[i]));
        if (str[0] == '=') {
            free(str);
            return (84);
        }
    }
    free(str);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (*env == NULL)
        return (84);
    if (want_help(ac, av))
        return (display_help(av[0]));
    if (error_handling(ac, av)) {
        write(2, "Bad Parameter\n", 14);
        display_help(av[0]);
        return (84);
    }
    return (tetris(ac, av));
}