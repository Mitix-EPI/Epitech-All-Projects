/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

int save_to_file_two(rpg_t *rpg, int fd)
{
    char *str = NULL;

    put_in_file_with_write(rpg->quest.tmp, fd);
    put_in_file_with_write(rpg->quest.scd_quest.nb_kills, fd);
    put_in_file_with_write(rpg->quest.scd_quest.nb_win, fd);
    put_in_file_with_write(rpg->fight->player.pos.x, fd);
    put_in_file_with_write(rpg->fight->player.pos.y, fd);
    put_in_file_with_write(rpg->fight->player.life, fd);
    for (int i = 0; i < 5; i += 1) {
        str = ftoa(rpg->fight->spell[i].sec, 2);
        write(fd, str, my_strlen(str));
        free(str);
        write(fd, ":", 1);
        put_in_file_with_write(rpg->fight->spell[i].damage, fd);
    }
    return (save_to_file_three(rpg, fd));
}

int save_to_file(rpg_t *rpg, game_obj_t *obj)
{
    int fd = 0;

    if (rpg->save == 1)
        fd = open("assets/save/First", O_WRONLY | O_TRUNC);
    if (rpg->save == 2)
        fd = open("assets/save/Second", O_WRONLY | O_TRUNC);
    if (rpg->save == 3)
        fd = open("assets/save/Third", O_WRONLY | O_TRUNC);
    put_in_file_with_write(rpg->status, fd);
    put_in_file_with_write(obj->rect.left, fd);
    put_in_file_with_write(obj->rect.top, fd);
    put_in_file_with_write(rpg->quest.act, fd);
    put_in_file_with_write(rpg->life, fd);
    put_in_file_with_write(rpg->tuto.executed, fd);
    put_in_file_with_write(rpg->quest.x, fd);
    put_in_file_with_write(rpg->quest.y, fd);
    put_in_file_with_write(rpg->level, fd);
    put_in_file_with_write(rpg->fps, fd);
    return (save_to_file_two(rpg, fd));
}