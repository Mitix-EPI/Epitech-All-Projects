/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void change_rotation_enn(sprite_t *sprite, int i, char charac)
{
    if (sprite->enn[i].direct == 'Z' && charac == 'D') {
        sfSprite_setRotation(sprite->enn[i].sprite, 90);
    }
    if (sprite->enn[i].direct == 'D' && charac == 'Z') {
        sfSprite_setRotation(sprite->enn[i].sprite, 360);
    }
    if (charac == 'S') {
        sfSprite_setRotation(sprite->enn[i].sprite, 180);
    }
    if (sprite->enn[i].direct == 'S' && charac == 'D') {
        sfSprite_setRotation(sprite->enn[i].sprite, 90);
    }
    if (sprite->enn[i].direct == 'Q' && charac == 'Z') {
        sfSprite_setRotation(sprite->enn[i].sprite, 360);
    }
    if (charac == 'Q')
        sfSprite_setRotation(sprite->enn[i].sprite, 270);
}

void place_enn(sprite_t *sprite, int x, int y, int i)
{
    char charac = 0;

    if (sprite->enn[i].pos.x > 0 && sprite->enn[i].pos.y > 0) {
        charac = sprite->map_[y][x];
        if (charac != sprite->enn[i].direct && charac != '1' \
        && charac != 'F' && charac != '0') {
            change_rotation_enn(sprite, i, charac);
            sprite->enn[i].direct = charac;
        }
        if (charac == 'F' && sprite->enn[i].status == 1) {
            sprite->life -= 1;
            sprite->life == 0 ? free_tow_enn(sprite) : 0;
            sprite->life == 0 ? sprite->statue = 4 : 0;
            sprite->life == 0 ? save_score(sprite) : 0;
            sprite->enn[i].status = 0;
            sprite->enn_alive -= 1;
        }
    }
}

void update_enn(sprite_t *sprite)
{
    int x = 0;
    int y = 0;
    int coeffx = calc_coeff(30, 'l', sprite);
    int coeffy = calc_coeff(30, 'h', sprite);

    for (int i = 0; i < sprite->nb_enn; i++) {
        y = (int)sprite->enn[i].pos.y / coeffy;
        x = (int)sprite->enn[i].pos.x / coeffx;
        if (y <= 35 && x <= 63) {
            place_enn(sprite, x, y, i);
        }
    }
}

void select_randomly_direct(sprite_t *sprite, int i)
{
    int r = generate_random(1, 2);

    if (r == 1) {
        sprite->enn[i].direct = 'Z';
        sprite->enn[i].pos.y -= croix(35, 'h', sprite);
        sfSprite_setRotation(sprite->enn[i].sprite, 360);
    } else {
        sprite->enn[i].direct = 'S';
        sprite->enn[i].pos.y += croix(35, 'h', sprite);
        sfSprite_setRotation(sprite->enn[i].sprite, 180);
    }
}

void move_enn(sprite_t *sprite)
{
    for (int i = 0; i < sprite->nb_enn; i++) {
        sprite->enn[i].time = sfClock_getElapsedTime(sprite->enn[i].clock);
        sprite->enn[i].second = sprite->enn[i].time.microseconds / 1000000.0;
        if (sprite->enn[i].second > 0.0001) {
            if (sprite->enn[i].direct == 'Z')
                sprite->enn[i].pos.y -= croix(2, 'h', sprite);
            if (sprite->enn[i].direct == 'S')
                sprite->enn[i].pos.y += croix(2, 'h', sprite);
            if (sprite->enn[i].direct == 'Q')
                sprite->enn[i].pos.x -= croix(2, 'l', sprite);
            if (sprite->enn[i].direct == 'D')
                sprite->enn[i].pos.x += croix(2, 'l', sprite);
            if (sprite->enn[i].direct == 'R')
                select_randomly_direct(sprite, i);
            sfSprite_setPosition(sprite->enn[i].sprite, sprite->enn[i].pos);
            sfClock_restart(sprite->enn[i].clock);
        }
    }
}
