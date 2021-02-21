/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

void get_str2(char *str, rpg_t *rpg, game_obj_t *obj)
{
    int size_tmp = 0;

    rpg->status = generic_save(str, &size_tmp);
    obj->rect.left = generic_save(str, &size_tmp);
    obj->rect.top = generic_save(str, &size_tmp);
    rpg->quest.act = generic_save(str, &size_tmp);
    rpg->life = generic_save(str, &size_tmp);
    rpg->tuto.executed = generic_save(str, &size_tmp);
    rpg->quest.x = generic_save(str, &size_tmp);
    rpg->quest.y = generic_save(str, &size_tmp);
    rpg->level = generic_save(str, &size_tmp);
    rpg->fps = generic_save(str, &size_tmp);
    rpg->quest.tmp = generic_save(str, &size_tmp);
    rpg->quest.scd_quest.nb_kills = generic_save(str, &size_tmp);
    rpg->quest.scd_quest.nb_win = generic_save(str, &size_tmp);
    rpg->fight->player.pos.x = generic_save(str, &size_tmp);
    rpg->fight->player.pos.y = generic_save(str, &size_tmp);
    rpg->fight->player.life = generic_save(str, &size_tmp);
    get_str3(str, size_tmp, rpg, obj);
}

void get_init(rpg_t *rpg, char *str, game_obj_t *obj)
{
    get_str2(str, rpg, obj);
    rpg->perspec.rect = obj->rect;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

int part_one_init_save(rpg_t *rpg, int *fd, struct stat *fileStat)
{
    if (rpg->save == 1) {
        *fd = open("assets/save/First", O_RDONLY);
        if (*fd == 84)
            return (84);
        if (stat("assets/save/First", fileStat) < 0)
            return (84);
    }
    if (rpg->save == 2) {
        *fd = open("assets/save/Second", O_RDONLY);
        if (*fd == 84)
            return (84);
        if (stat("assets/save/Second", fileStat) < 0)
            return (84);
    }
    return (0);
}

int part_two_init_save(rpg_t *rpg, int *fd, struct stat *fileStat)
{

    if (rpg->save == 3) {
        *fd = open("assets/save/Third", O_RDONLY);
        if (*fd == 84)
            return (84);
        if (stat("assets/save/Third", fileStat) < 0)
            return (84);
    }
    return (0);
}

int init_save(rpg_t *rpg, game_obj_t *obj)
{
    struct stat fileStat;
    char *str = NULL;
    int fd = 0;
    int a = 0;

    if (part_one_init_save(rpg, &fd, &fileStat) != 0)
        return (84);
    if (part_two_init_save(rpg, &fd, &fileStat) != 0)
        return (84);
    str = malloc(sizeof(char) * (fileStat.st_size));
    a = read(fd, str, fileStat.st_size);
    str[fileStat.st_size - 1] = '\0';
    if (a == -1) {
        write(2, "read failed\n", 13);
        return (84);
    }
    get_init(rpg, str, obj);
    return (0);
}
