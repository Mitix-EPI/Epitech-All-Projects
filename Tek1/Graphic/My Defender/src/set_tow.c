/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void delete_tow(sprite_t *sprite, sfVector2i mouse)
{
    int x = (int)(mouse.x / croix(30, 'l', sprite));
    int y = (int)(mouse.y / croix(30, 'h', sprite));

    for (int a = 0; a < sprite->nb_tow; a++) {
        if ((int)(sprite->tow[a].pos.y / croix(30, 'h', sprite)) == y && \
        (int)(sprite->tow[a].pos.x / croix(30, 'h', sprite)) == x && \
        sprite->map_[(int)(sprite->tow[a].pos.y / croix(30, 'h', sprite))]\
            [(int)(sprite->tow[a].pos.x / croix(30, 'h', sprite))] >= '6' && \
            sprite->map_[(int)(sprite->tow[a].pos.y / croix(30, 'h', sprite))]\
            [(int)(sprite->tow[a].pos.x / croix(30, 'h', sprite))] <= '9') {
            sprite->map_[(int)(sprite->tow[a].pos.y / croix(30, 'h', sprite))]\
            [(int)(sprite->tow[a].pos.x / croix(30, 'h', sprite))] = '0';
            sprite->tow[a].status = 0;
            sprite->gold += 100;
            sprite->tow_alive -= 1;
        }
    }
}

void bomb(sprite_t *sprite, sfVector2i mouse)
{
    if (sprite->cursor == 5 && sprite->gold >= 2500) {
        sprite->gold -= 2500;
        sfMusic_play(sprite->bomb_sound);
        shoot_bomb(sprite, 100, mouse);
    }
    if (sprite->cursor == 6 && sprite->gold >= 5000) {
        sprite->gold -= 5000;
        sfMusic_setVolume(sprite->bomb_sound, 120);
        shoot_bomb(sprite, 250, mouse);
        sfMusic_play(sprite->bomb_sound);
        sfMusic_setVolume(sprite->bomb_sound, 80);
    }
}

void pos_tower(sprite_t *sprite, sfVector2i mouse)
{
    int x = (int)(mouse.x / croix(30, 'l', sprite));
    int y = (int)(mouse.y / croix(30, 'h', sprite));

    if (sprite->cursor == 5 && (mouse.x < croix(624, 'l', sprite) || \
    mouse.x > croix(1061, 'l', sprite) || mouse.y < croix(750, 'h', sprite)) \
    || sprite->cursor == 6 && (mouse.x < croix(624, 'l', sprite) || mouse.x \
    > croix(1061, 'l', sprite) || mouse.y < croix(750, 'h', sprite))) {
        bomb(sprite, mouse);
        return;
    }
    if (x <= 63 && y <= 35 && sprite->map_[y][x] == '0') {
        if (mouse.x < croix(624, 'l', sprite) || mouse.x > croix\
        (1061, 'l', sprite) || mouse.y < croix(750, 'h', sprite)) {
            gold_loose(sprite, x, y, mouse);
        }
    }
}

void add_tow(sprite_t *sprite, int nb, sfVector2i mouse)
{
    int i = 0;

    for (; sprite->tow[i].sprite != NULL; i++)
        if (sprite->tow[i].status == 0)
            break;
    sprite->tow[i].rect.left = nb * 100;
    sprite->tow[i].tow = nb + 1;
    sprite->tow[i].pos.x = (float)mouse.x;
    sprite->tow[i].pos.y = (float)mouse.y;
    sfSprite_setTextureRect(sprite->tow[i].sprite, sprite->tow[i].rect);
    sfSprite_setPosition(sprite->tow[i].sprite, sprite->tow[i].pos);
    sprite->tow[i].status = 1;
    sprite->nb_tow += 1;
    sprite->tow_alive += 1;
    sfMusic_play(sprite->tow_input);
}

void set_towers(sprite_t *sprite)
{
    char *path = "sprite/all_tower.png";
    sfVector2f pos = {};
    sfVector2f scale = {1, 1};

    for (int i = 0; i < 100; i++) {
        pos.x = 0;
        pos.y = 0;
        sprite->tow[i] = init_tower(path, pos, scale);
    }
    sprite->tow[100].sprite = NULL;
}