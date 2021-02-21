/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main_corewar
*/

#include "corewar.h"

int count_champs(char **av, int ac)
{
    int count = 0;

    for (int i = 1; i < ac; i++) {
        if (exact_extension(av[i], ".cor") != 0)
            count++;
    }
    return (count);
}

void complete_struct_for_all_champions(core_t *core, char **av, int ac)
{
    static int nb = 0;

    for (int i = 1; i < ac; i++) {
        if (exact_extension(av[i], ".cor") != 0) {
            fill_champ(&core->champs[nb], av[i]);
            nb += 1;
        }
    }
}

void disp_all_champs(core_t *core)
{
    for (int i = 0; i < core->nb_champs; i++) {
        printf("Name : %s\n", core->champs[i].header.prog_name);
        printf("Comment : %s\n", core->champs[i].header.comment);
        for (int j = 2192; j < 2192 + core->champs[i].header.prog_size; j++)
            printf("instructs : %x\n", core->champs[i].instructs[j]);
    }
}

char *copy_champ_in_arena(char *src, char *champ, int address, int size)
{
    int j = 0;

    printf("ADRESSE : %d | SIZE : %d \n", address, size);
    for (int i = address; champ && src && j < size; i++, j++)
        src[i] = champ[j];
    return (src);
}

char *copy_champ_color(char *src, int address, champions_t champ, int i)
{
    char c = 0;
    int len = 0;

    if (i == 0)
        c = 'B';
    if (i == 1)
        c = 'R';
    if (i == 2)
        c = 'G';
    if (i == 3)
        c = 'Y';
    for (int k = address; src && len < champ.header.prog_size; k++, len++) {
        src[k] = c;
    }
    return (src);
}

void mallocs_vm(core_t *core)
{
    core->arena = malloc(sizeof(char) * (MEM_SIZE + 1));
    core->color_txt = malloc(sizeof(char) * (MEM_SIZE + 1));
    for (int i = 0; i <= MEM_SIZE; i++) {
        core->arena[i] = 0;
        core->color_txt[i] = 0;
    }
    core->arena[MEM_SIZE] = 0;
    core->color_txt[MEM_SIZE] = 0;
    for (int i = 0; i < core->nb_champs; i++) {
        core->arena = copy_champ_in_arena(core->arena, \
        &core->champs[i].instructs[2192], core->champs[i].pc, \
        core->champs[i].header.prog_size);
        core->color_txt = copy_champ_color(core->color_txt, core->champs[i].pc,
        core->champs[i], i);
        core->champs[i].wait = 0;
        core->champs[i].carry = 1;
    }
}

void set_addresses(core_t *core, char **av, int ac)
{
    int tmp = 0;

    for (int i = 0; i < core->nb_champs; i++) {
        core->champs[i].pc = (i * 1024);
        core->champs[i].id = i + 1;
    }
    for (int i = 1; i < ac; i++) {
        flag_a(av, i, core, ac);
        flag_n(av, i, core, ac);
    }
}

void set_values(core_t *core, char **av, int ac)
{
    core->nb_live = NBR_LIVE;
    core->ctd = CYCLE_TO_DIE;
    for (int i = 0; i < core->nb_champs; i++)
        core->champs[i].reg[0] = i + 1;
    int tmp = 0;
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-dump") == 0) {
            if ((av[i + 1][0] < 48 || av[i + 1][0] > 57)) {
                my_putstr(2, "Error : Argument after -d isn't a \
valid number\n");
                exit(84);
            }
            core->dump = 1;
            core->dump_nbr = my_atoi(av[i + 1]);
        }
    }
    set_addresses(core, av, ac);
    mallocs_vm(core);
}

void main_corewar(char **av, int ac)
{
    core_t core;

    core.nb_champs = count_champs(av, ac);
    if (core.nb_champs < 1)
        my_exit(NOT_ENOUGHT_CHAMPS);
    core.champs = malloc(sizeof(champions_t) * (core.nb_champs + 1));
    complete_struct_for_all_champions(&core, av, ac);
    disp_all_champs(&core);
    set_values(&core, av, ac);
    loop(&core);
}
