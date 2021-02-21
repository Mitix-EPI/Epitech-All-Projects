/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void draw_cursor(sfRenderWindow *window, sprite_t *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    (sprite->cursor == 0) ? sfRenderWindow_setMouseCursorVisible(window, \
    sfTrue) : sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    if (sprite->cursor != 0) {
    sfRenderWindow_drawCircleShape(window, sprite->circle, NULL);
    sfCircleShape_setPosition(sprite->circle, (sfVector2f){mouse.x, mouse.y});
    draw_cursor_one(sprite, window, mouse);
    }
    draw_cursor_one(sprite, window, mouse);
}

void display_gold(sprite_t *sprite, sfRenderWindow *window)
{
    char *text = cat(int_to_string(sprite->gold), "$");

    sfText_setString(sprite->text_gold, text);
    sfText_setFont(sprite->text_gold, sprite->font_gold);
    sfText_setCharacterSize(sprite->text_gold, 50 * sprite->hight / 1920);
    sfText_setColor(sprite->text_gold, sfYellow);
    sfRenderWindow_drawText(window, sprite->text_gold, NULL);
    sfText_setPosition(sprite->text_gold, (sfVector2f){croix\
    (1800, 'l', sprite), croix(0, 'h', sprite)});
}

void display_life(sfRenderWindow *window, sprite_t *sprite)
{
    char *text = cat("life : ", int_to_string(sprite->life));

    sfText_setString(sprite->text_life, text);
    sfText_setFont(sprite->text_life, sprite->font_life);
    sfText_setCharacterSize(sprite->text_life, 50 * sprite->hight / 1920);
    sfText_setColor(sprite->text_life, sfRed);
    sfRenderWindow_drawText(window, sprite->text_life, NULL);
    sfText_setPosition(sprite->text_life, (sfVector2f){croix\
    (100, 'l', sprite), croix(1, 'h', sprite)});
    free(text);
}