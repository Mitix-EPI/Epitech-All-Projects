/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void draw_cursor_two(sprite_t *sprite, sfRenderWindow *window, \
sfVector2i mouse)
{
    if (sprite->cursor == 3) {
        sfSprite_setScale(sprite->tower_3, (sfVector2f){1 * sprite->hight \
        / 1920, 1 * sprite->weidth / 1080});
        sfSprite_setPosition( sprite->tower_3, (sfVector2f){mouse.x
        - croix(50, 'l', sprite) , mouse.y - croix(50, 'h', sprite)});
        sfCircleShape_setRadius(sprite->circle, croix(200, 'l', sprite));
        sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
        (200, 'l', sprite), croix(200, 'l', sprite)});
        sfRenderWindow_drawSprite(window, sprite->tower_3, NULL);
    }
    if (sprite->cursor == 4) {
        sfSprite_setScale(sprite->tower_4, (sfVector2f){1 * sprite->hight \
        / 1920, 1 * sprite->weidth / 1080});
        sfSprite_setPosition( sprite->tower_4, (sfVector2f){mouse.x
        - croix(50, 'l', sprite) , mouse.y - croix(50, 'h', sprite)});
        sfCircleShape_setRadius(sprite->circle, croix(200, 'l', sprite));
        sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
        (200, 'l', sprite), croix(200, 'l', sprite)});
        sfRenderWindow_drawSprite(window, sprite->tower_4, NULL);
    }
    draw_cursor_tree(sprite, window, mouse);
}

void draw_cursor_tree(sprite_t *sprite, sfRenderWindow *window, \
sfVector2i mouse)
{
    if (sprite->cursor == 5) {
        sfSprite_setScale(sprite->little_bomb, (sfVector2f){1 * sprite->hight \
        / 1920, 1 * sprite->weidth / 1080});
        sfSprite_setPosition( sprite->little_bomb, (sfVector2f){mouse.x
        - croix(50, 'l', sprite) , mouse.y - croix(50, 'h', sprite)});
        sfCircleShape_setRadius(sprite->circle, croix(100, 'l', sprite));
        sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
        (100, 'l', sprite), croix(100, 'l', sprite)});
        sfRenderWindow_drawSprite(window, sprite->little_bomb, NULL);
    }
    if (sprite->cursor == 6) {
        sfSprite_setScale(sprite->big_bomb, (sfVector2f){1 * sprite->hight \
        / 1920, 1 * sprite->weidth / 1080});
        sfSprite_setPosition(sprite->big_bomb, (sfVector2f){mouse.x
        - croix(50, 'l', sprite) , mouse.y - croix(50, 'h', sprite)});
        sfCircleShape_setRadius(sprite->circle, croix(250, 'l', sprite));
        sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
        (250, 'l', sprite), croix(250, 'l', sprite)});
        sfRenderWindow_drawSprite(window, sprite->big_bomb, NULL);
    }
}

void draw_cursor_one(sprite_t *sprite, sfRenderWindow *window, \
sfVector2i mouse)
{
    if (sprite->cursor == 1) {
        sfSprite_setScale(sprite->tower_1, (sfVector2f){1 * sprite->hight \
        / 1920, 1 * sprite->weidth / 1080});
        sfSprite_setPosition(sprite->tower_1, (sfVector2f){mouse.x
        - croix(50, 'l', sprite) , mouse.y - croix(50, 'h', sprite)});
        sfCircleShape_setRadius(sprite->circle, croix(200, 'l', sprite));
        sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
        (200, 'l', sprite), croix(200, 'l', sprite)});
        sfRenderWindow_drawSprite(window, sprite->tower_1, NULL);
    }
    if (sprite->cursor == 2) {
        sfSprite_setScale(sprite->tower_2, (sfVector2f){1 * sprite->hight / \
        1920, 1 * sprite->weidth / 1080});
        sfSprite_setPosition( sprite->tower_2, (sfVector2f){mouse.x \
        - croix(50, 'l', sprite) , mouse.y - croix(50, 'h', sprite)});
        sfCircleShape_setRadius(sprite->circle, croix(200, 'l', sprite));
        sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
        (200, 'l', sprite), croix(200, 'l', sprite)});
        sfRenderWindow_drawSprite(window, sprite->tower_2, NULL);
    }
    draw_cursor_two(sprite, window, mouse);
}