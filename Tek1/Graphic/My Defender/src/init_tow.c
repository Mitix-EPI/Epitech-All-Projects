/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

sfSprite *tower_1(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 100;
    rect_btn.height = 100;
    btn_texture = sfTexture_createFromFile("sprite/tower_1.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    return (btn);
}

sfSprite *tower_2(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 100;
    rect_btn.height = 100;
    btn_texture = sfTexture_createFromFile("sprite/tower_2.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    return (btn);
}

sfSprite *tower_3(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 100;
    rect_btn.height = 100;
    btn_texture = sfTexture_createFromFile("sprite/tower_3.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    return (btn);
}

sfSprite *tower_4(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 100;
    rect_btn.height = 100;
    btn_texture = sfTexture_createFromFile("sprite/tower_4.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    return (btn);
}

struct towers_c init_tower(char *path, sfVector2f pos, sfVector2f scale)
{
    towers_t tow;
    tow.rect.top = 0;
    tow.rect.left = 0;
    tow.rect.width = 100;
    tow.rect.height = 100;

    tow.sprite = sfSprite_create();
    tow.txtre = sfTexture_createFromFile(path, NULL);
    tow.pos = pos;
    sfSprite_setOrigin(tow.sprite, (sfVector2f) {50, 50});
    sfSprite_setTexture(tow.sprite, tow.txtre, sfTrue);
    sfSprite_setPosition(tow.sprite, tow.pos);
    sfSprite_setTextureRect(tow.sprite, tow.rect);
    sfSprite_setScale(tow.sprite, scale);
    tow.clock = sfClock_create();
    tow.status = 0;
    return (tow);
}