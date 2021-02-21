/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

float angle(sprite_t *sprite, int i, int a)
{
    double diff_x = (sprite->tow[i].pos.x - sprite->enn[a].pos.x);
    double diff_y =  (sprite->tow[i].pos.y - sprite->enn[a].pos.y);
    float angle = atan2f(diff_y, diff_x) * (180.0 / M_PI) - 90;

    return (angle);
}

void shoot_tow_one(sprite_t *sprite, int i)
{
    double diff_x = 0;
    double diff_y = 0;

    if (sprite->tow[i].second > 2) {
        for (int a = 0; a < sprite->nb_enn; a++) {
            diff_x = pow(sprite->enn[a].pos.x - sprite->tow[i].pos.x, 2);
            diff_y =  pow(sprite->tow[i].pos.y - sprite->enn[a].pos.y, 2);
            if (sqrt(diff_x + diff_y) <  croix(200, 'l', sprite) \
            && sprite->enn[a].status != 0 && sprite->tow[i].status != 0) {
                sprite->enn[a].status = 0;
                sprite->gold += 10;
                sfSprite_setRotation(sprite->tow[i].sprite, angle\
                (sprite, i, a));
                sprite->enn_alive -= 1;
                sfMusic_play(sprite->tow_shot);
                break;
            }
        }
        sfClock_restart(sprite->tow[i].clock);
    }
}

void shoot_tow_two(sprite_t *sprite, int i)
{
    double diff_x = 0;
    double diff_y = 0;

    if (sprite->tow[i].second > 1) {
        for (int a = 0; a < sprite->nb_enn; a++) {
            diff_x = pow(sprite->enn[a].pos.x - sprite->tow[i].pos.x, 2);
            diff_y =  pow(sprite->tow[i].pos.y - sprite->enn[a].pos.y, 2);
            if (sqrt(diff_x + diff_y) <  croix(200, 'l', sprite) \
            && sprite->enn[a].status != 0 && sprite->tow[i].status != 0) {
                sprite->enn[a].status = 0;
                sprite->gold += 10;
                sfSprite_setRotation(sprite->tow[i].sprite, angle\
                (sprite, i, a));
                sprite->enn_alive -= 1;
                sfMusic_play(sprite->tow_shot);
                break;
            }
        }
        sfClock_restart(sprite->tow[i].clock);
    }
}

void shoot_tow_tree(sprite_t *sprite, int i)
{
    double diff_x = 0;
    double diff_y = 0;

    if (sprite->tow[i].second > 0.5) {
        for (int a = 0; a < sprite->nb_enn; a++) {
            diff_x = pow(sprite->enn[a].pos.x - sprite->tow[i].pos.x, 2);
            diff_y =  pow(sprite->tow[i].pos.y - sprite->enn[a].pos.y, 2);
            if (sqrt(diff_x + diff_y) < croix(200, 'l', sprite) \
            && sprite->enn[a].status != 0 && sprite->tow[i].status != 0) {
                sprite->enn[a].status = 0;
                sprite->gold += 10;
                sfSprite_setRotation(sprite->tow[i].sprite, angle\
                (sprite, i, a));
                sprite->enn_alive -= 1;
                sfMusic_play(sprite->tow_shot);
                break;
            }
        }
        sfClock_restart(sprite->tow[i].clock);
    }
}

void shoot_tow_four(sprite_t *sprite, int i)
{
    double diff_x = 0;
    double diff_y = 0;

    if (sprite->tow[i].second > 0.25) {
        for (int a = 0; a < sprite->nb_enn; a++) {
            diff_x = pow(sprite->enn[a].pos.x - sprite->tow[i].pos.x, 2);
            diff_y =  pow(sprite->tow[i].pos.y - sprite->enn[a].pos.y, 2);
            if (sqrt(diff_x + diff_y) < croix(200, 'l', sprite) \
            && sprite->enn[a].status != 0 && sprite->tow[i].status != 0) {
                sprite->enn[a].status = 0;
                sprite->gold += 10;
                sfSprite_setRotation(sprite->tow[i].sprite, angle\
                (sprite, i, a));
                sprite->enn_alive -= 1;
                sfMusic_play(sprite->tow_shot);
                break;
            }
        }
        sfClock_restart(sprite->tow[i].clock);
    }
}
