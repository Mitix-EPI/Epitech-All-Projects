/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

int player_deplacement(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move_up(&rpg->player);
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move_down(&rpg->player);
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_left(&rpg->player);
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        move_right(&rpg->player);
        return (0);
    }
    dont_move(&rpg->player);
    return (0);
}

void analyse_event(rpg_t *rpg, game_obj_t *obj)
{
    if (rpg->evnt.type == sfEvtClosed || (rpg->evnt.type == sfEvtKeyPressed \
    && rpg->evnt.key.code == sfKeyEscape)) {
        sfRenderWindow_close(rpg->win);
    }
    if (rpg->evnt.type == sfEvtMouseButtonPressed) {
        clics_handlings(rpg->evnt.mouseButton, rpg, obj);
    }
    if (rpg->evnt.type == sfEvtKeyPressed) {
        keys_handlings(rpg->evnt, rpg, obj);
    }
}

void move_x(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset)
{
    if (offset > 0) {
        pos.x -= 16;
        pos.x /= 32;
        pos.y /= 32;
        if (pos.x + 1 < 140 && rpg->map[pos.y][pos.x + 1]) {
            obj->rect.left += offset;
            rpg->quest.x += offset;
        }
    } else {
        pos.x += 16;
        pos.x /= 32;
        pos.y /= 32;
        if (pos.x > 0 && rpg->map[pos.y][pos.x - 1]) {
            obj->rect.left += offset;
            rpg->quest.x += offset;
        }
    }
}

void move_y(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset)
{
    if (offset > 0) {
        pos.y -= 16;
        pos.y /= 32;
        pos.x /= 32;
        if (pos.y + 1 < 140 && rpg->map[pos.y + 1][pos.x]) {
            obj->rect.top += offset;
            rpg->quest.y += offset;
        }
    } else {
        pos.y += 16;
        pos.y /= 32;
        pos.x /= 32;
        if (pos.y > 0 && rpg->map[pos.y - 1][pos.x]) {
            obj->rect.top += offset;
            rpg->quest.y += offset;
        }
    }
}

void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg)
{
    sfVector2i pos = {((obj->rect.left) + 480 - 16),
    ((obj->rect.top) + 270 - 16)};

    pos.x *= 2;
    pos.y *= 2;
    if (mouvement.x != 0)
        move_x(pos, obj, rpg, mouvement.x);
    if (mouvement.y != 0)
        move_y(pos, obj, rpg, mouvement.y);
    pos.x /= 32;
    pos.y /= 32;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    rpg->perspec.rect = obj->rect;
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}
