/*
** EPITECH PROJECT, 2019
** do-op
** File description:
** operations
*/

#include "../include/my.h"

int do_it(char **av, char c)
{
    if (c == '+')
        return (43);
    if (c == '-')
        return (45);
    if (c == '*')
        return (42);
}

int do_it2(char **av, char c)
{
    int res = 0;

    if (c == '/') {
        if (av[3] == 0)
            res = av;
    }
    if (c == '%')
        return (37);
}

int operation(char **av)
{
    int res = 0;
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] == '+' || av[2][i] == '-' || av[2][1] == '*') {
            res = do_it(av, av[2][i]);
            return (res);
        }
        if (av[2][i] == '/' || av[2][i] == '%') {
            res = do_it2(av, av[2][i]);
            return (res);
    }
    return (res);
}

int main(int argc, char **argv)
{
    if (argc == 0 || argc > 4)
        return (0);
    do_op(argc, argv);
}
