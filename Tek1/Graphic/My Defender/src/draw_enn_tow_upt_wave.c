/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void update_waves(sprite_t *sprite)
{
    sfVector2f pos;

    if (sprite->enn_alive == 0) {
        sprite->vague += 1;
        if (sprite->vague == 50) {
            free_tow_enn(sprite);
            sprite->statue = 5;
            save_score(sprite);
            return;
        }
        update_nb_enn(sprite);
        for (int a = 0; a < sprite->nb_enn; a++) {
            pos = set_good_pos(sprite);
            sprite->enn[a].pos = pos;
            sprite->enn[a].direct = set_good_direc(pos.x, pos.y, \
            sprite->enn[a].sprite, sprite);
            sfSprite_setPosition(sprite->enn[a].sprite, sprite->enn[a].pos);
            sprite->enn[a].status = 1;
        }
        update_type_enn(sprite);
    }
}

void draw_enn(sprite_t *sprite, sfRenderWindow *window)
{
    for (int i = 0; i < sprite->nb_enn; i++) {
        if (sprite->enn[i].status != 0) {
            sfSprite_setScale(sprite->enn[i].sprite, (sfVector2f) {croix\
            (1, 'l', sprite), croix(1, 'h', sprite)});
            sfRenderWindow_drawSprite(window, sprite->enn[i].sprite, NULL);
        }
    }
}

void draw_tow(sprite_t *sprite, sfRenderWindow *window)
{
    for (int i = 0; i < 100; i++) {
        if (sprite->tow[i].status == 1) {
            sfSprite_setScale(sprite->tow[i].sprite, (sfVector2f){croix\
            (1, 'l', sprite), croix(1, 'h', sprite)});
            sfRenderWindow_drawSprite(window, sprite->tow[i].sprite, NULL);
        }
    }
}