/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** flags
*/

#include "corewar.h"

int idx_next_champion(char **av, int ac, int i, core_t *core)
{
    int res = 0;

    for (; i < ac; i++) {
        if (exact_extension(av[i], ".cor") != 0)
            break;
    }
    for (int j = 0; j < core->nb_champs; j++)
        if (my_strcmp(core->champs[j].path, av[i]) == 0)
            return (j);
    return (-84);
}

void flag_a(char **av, int i, core_t *core, int ac)
{
    int tmp = 0;

    if (my_strcmp(av[i], "-a") == 0) {
        if ((av[i + 1][0] < 48 || av[i + 1][0] > 57)) {
            my_putstr(2, "Error : Argument after -a isn't a valid number\n");
            exit(84);
        }
        tmp = idx_next_champion(av, ac, i, core);
        if (tmp == -84) {
            my_putstr(2, "Error : -a not associated to a champion\n");
            exit(84);
        }
        core->champs[tmp].pc = my_atoi(av[i + 1]);
    }
}

int id_already_taken(core_t *core, int id, int idx)
{
    for (int i = 0; i < core->nb_champs; i++)
        if (core->champs[i].id == id && idx != i)
            return (1);
    return (0);
}

void flag_n(char **av, int i, core_t *core, int ac)
{
    int tmp = 0;

    if (my_strcmp(av[i], "-n") == 0) {
        printf("INCROYABLE\n");
        if ((av[i + 1][0] < 48 || av[i + 1][0] > 57)) {
            my_putstr(2, "Error : Argument after -n isn't a valid number\n");
            exit(84);
        }
        tmp = idx_next_champion(av, ac, i, core);
        if (tmp == -84) {
            my_putstr(2, "Error : -n not associated to a champion\n");
            exit(84);
        }
        if (id_already_taken(core, my_atoi(av[i + 1]), tmp))
            my_exit(ID_ALREADY_TAKEN);
        core->champs[tmp].id = my_atoi(av[i + 1]);
    }
}
