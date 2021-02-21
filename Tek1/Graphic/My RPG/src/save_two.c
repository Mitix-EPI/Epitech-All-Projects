/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

char *stock_info2(char *str, int *size_tmp)
{
    int size = 0;
    char *tmp = NULL;

    for (size = *size_tmp; str[size] && str[size] != ':'; size += 1);
    tmp = malloc(sizeof(char) * (size - *size_tmp + 1));
    tmp[size - *size_tmp] = '\0';
    for (size = *size_tmp; str[size] && str[size] != ':'; size += 1)
        tmp[size - *size_tmp] = str[size];
    if (str[size])
        *size_tmp = size + 1;
    return (tmp);
}

float generic_save_stof(char *str, int *size_tmp)
{
    char *tmp = NULL;
    float res = 0;

    tmp = stock_info2(str, size_tmp);
    res = stof(tmp);
    free(tmp);
    return (res);
}

int generic_save(char *str, int *size_tmp)
{
    char *tmp = NULL;
    int res = 0;

    tmp = stock_info2(str, size_tmp);
    res = my_getnbr(tmp);
    free(tmp);
    return (res);
}

void get_str3(char *str, int tmp, rpg_t *rpg,
__attribute__((unused))game_obj_t *obj)
{
    int size_tmp = tmp;

    for (int i = 0; i < 5; i++) {
        rpg->fight->spell[i].sec = generic_save_stof(str, &size_tmp);
        rpg->fight->spell[i].damage = generic_save(str, &size_tmp);
    }
    rpg->fight->enns[0].velocity = generic_save_stof(str, &size_tmp);
    rpg->fight->nb_enn = generic_save(str, &size_tmp);
    for (int i = 0; i < rpg->fight->nb_enn; i += 1) {
        rpg->fight->enns[i].life = generic_save(str, &size_tmp);
        rpg->fight->enns[i].pos.x = generic_save(str, &size_tmp);
        rpg->fight->enns[i].pos.y = generic_save(str, &size_tmp);
        rpg->fight->enns[i].tmp = generic_save(str, &size_tmp);
    }
}
