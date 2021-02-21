/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

sfSprite *little_bomb(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 100;
    rect_btn.height = 100;
    btn_texture = sfTexture_createFromFile("sprite/little_bomb.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    return (btn);
}

sfSprite *big_bomb(sfRenderWindow *windows, sprite_t *sprites)
{
    sfIntRect rect_btn;
    sfSprite* btn;
    sfTexture* btn_texture;

    rect_btn.top = 0;
    rect_btn.left = 0;
    rect_btn.width = 100;
    rect_btn.height = 100;
    btn_texture = sfTexture_createFromFile("sprite/big_bomb.png", NULL);
    btn = sfSprite_create();
    sfSprite_setTexture(btn, btn_texture, sfTrue);
    sfSprite_setTextureRect(btn, rect_btn);
    return (btn);
}
