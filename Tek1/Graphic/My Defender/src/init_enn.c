/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void update_nb_enn(sprite_t *sprite)
{
    sprite->nb_enn = 20 * sprite->vague;
    sprite->enn_alive = sprite->nb_enn;
}

void update_type_enn(sprite_t *sprite)
{
    for (int i = 0; i < sprite->nb_enn; i++) {
        if (sprite->enn[i].type == 1) {
            sprite->enn[i].rect.left = 0;
        }
        if (sprite->enn[i].type == 2) {
            sprite->enn[i].rect.left = 64;
        }
        if (sprite->enn[i].type == 3) {
            sprite->enn[i].rect.left = 128;
        }
        sfSprite_setTextureRect(sprite->enn[i].sprite, sprite->enn[i].rect);
    }
}

struct ennemies_c init_enemy(char *path, sfVector2f pos, sfVector2f scale, \
sprite_t *sprite)
{
    ennemies_t enn;

    enn.sprite = NULL;
    enn.txtre = sfTexture_createFromFile(path, NULL);
    enn.sprite = sfSprite_create();
    sfSprite_setTexture(enn.sprite, enn.txtre, sfTrue);
    enn.pos = pos;
    enn.type = 1;
    enn.rect.top = 0;
    enn.rect.left = 0;
    enn.rect.height = 64;
    enn.rect.width = 64;
    sfSprite_setTextureRect(enn.sprite, enn.rect);
    sfSprite_setPosition(enn.sprite, pos);
    sfSprite_setOrigin(enn.sprite, (sfVector2f){32, 32});
    enn.direct = set_good_direc(pos.x, pos.y, enn.sprite, sprite);
    enn.life = 3;
    enn.status = 1;
    enn.clock = sfClock_create();
    return (enn);
}

char set_good_direc(float x, float y, sfSprite *sprt, sprite_t *sprite)
{
    if (x < 0) {
        sfSprite_setRotation(sprt, 90);
        return ('D');
    }
    if (y < 0) {
        sfSprite_setRotation(sprt, 180);
        return ('S');
    }
    if (x > croix(1920, 'l', sprite) && y > 0) {
        sfSprite_setRotation(sprt, 270);
        return ('Q');
    }
    sfSprite_setRotation(sprt, 360);
    return ('Z');
}

void set_ennemies(sprite_t *sprite)
{
    char *path = "sprite/ennemies_spritesheet.png";
    sfVector2f scale = {1, 1};
    sfVector2f pos = {};

    srand(time(0));
    for (int i = 0; i < 10000; i++) {
        pos = set_good_pos(sprite);
        sprite->enn[i] = init_enemy(path, pos, scale, sprite);
    }
    sprite->enn[10000].sprite = NULL;
}