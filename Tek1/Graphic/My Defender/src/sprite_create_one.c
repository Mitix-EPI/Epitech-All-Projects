/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

sfSprite *menu_btn(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;
    sfVector2f game_btn_pos = {50 * sprites->hight / 900, 270 * \
    sprites->weidth / 500};

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 1920;
    rect_btn.height = 1080;
    btn_texture = sfTexture_createFromFile("sprite/btn.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    sfSprite_setPosition(btn, game_btn_pos);
    return (btn);
}

sfSprite *lvl(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;
    sfVector2f game_btn_pos = {0, 0};

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 1920;
    rect_btn.height = 1080;
    btn_texture = sfTexture_createFromFile("sprite/lvl btn.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    sfSprite_setPosition(btn, game_btn_pos);
    return (btn);
}

sfSprite *sound_volume(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;
    sfVector2f game_btn_pos = {200 * sprites->hight / 1920, 200 * \
    sprites->weidth / 1080};

    rect_btn.top = 64;
    rect_btn.left = 0;
    rect_btn.width = 192;
    rect_btn.height = 32;
    btn_texture = sfTexture_createFromFile\
    ("sprite/sound_progress_bar.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    sfSprite_setPosition(btn, game_btn_pos);
    return (btn);
}

sfSprite *back_opt(sfRenderWindow *window)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_testure;
    sfVector2f game_btn_pos = {0, 0};

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 1920;
    rect_btn.height = 1080;
    btn_testure = sfTexture_createFromFile("sprite/test.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_testure, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    sfSprite_setPosition(btn, game_btn_pos);
    return (btn);
}

sfSprite *map(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;
    sfVector2f game_btn_pos = {0, 0};

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 1920;
    rect_btn.height = 1080;
    btn_texture = sfTexture_createFromFile("sprite/map1.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    sfSprite_setPosition(btn, game_btn_pos);
    return (btn);
}