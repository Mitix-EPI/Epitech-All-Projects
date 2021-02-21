/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gold_loose
*/

#include "../my_tower.h"

void shoot_bomb(sprite_t *sprite, int d, sfVector2i mouse)
{
    double diff_x = 0;
    double diff_y = 0;

    for (int a = 0; a < sprite->nb_enn; a++) {
        diff_x = pow(sprite->enn[a].pos.x - mouse.x, 2);
        diff_y =  pow(mouse.y - sprite->enn[a].pos.y, 2);
        if (sqrt(diff_x + diff_y) <  croix(d, 'l', sprite) \
        && sprite->enn[a].status != 0) {
            sprite->enn[a].status = 0;
            sprite->gold += 10;
            sprite->enn_alive -= 1;
        }
    }
}

void gold_loose_two(sprite_t *sprite, int x, int y, sfVector2i mouse)
{
    if (sprite->cursor == 4 && sprite->gold >= 1500) {
        sprite->gold -= 1500;
        sprite->map_[y][x] = '9';
        add_tow(sprite, 3, mouse);
        sprite->tow->nb_tow += 1;
    }
}

void gold_loose(sprite_t *sprite, int x, int y, sfVector2i mouse)
{
    if (sprite->tow_alive == 99)
        return;
    if (sprite->cursor == 1 && sprite->gold >= 100) {
        sprite->gold -= 100;
        sprite->map_[y][x] = '6';
        add_tow(sprite, 0, mouse);
        sprite->tow->nb_tow += 1;
    }
    if (sprite->cursor == 2 && sprite->gold >= 300) {
        sprite->gold -= 300;
        sprite->map_[y][x] = '7';
        add_tow(sprite, 1, mouse);
        sprite->tow->nb_tow += 1;
    }
    if (sprite->cursor == 3 && sprite->gold >= 700) {
        sprite->gold -= 700;
        sprite->map_[y][x] = '8';
        add_tow(sprite, 2, mouse);
        sprite->tow->nb_tow += 1;
    }
    gold_loose_two(sprite, x, y, mouse);
}