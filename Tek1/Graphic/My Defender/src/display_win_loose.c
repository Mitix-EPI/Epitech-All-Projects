/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void win(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    display_win(sprite);
    display_score(sprite);
    sfRenderWindow_drawText(window, sprite->text_loose, NULL);
    sfRenderWindow_drawText(window, sprite->text_display_score, NULL);
    sfRenderWindow_drawText(window, sprite->text_score, NULL);
    sfRenderWindow_display(window);
}

void loose(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    display_loose(sprite);
    display_score(sprite);
    sfRenderWindow_drawText(window, sprite->text_loose, NULL);
    sfRenderWindow_drawText(window, sprite->text_display_score, NULL);
    sfRenderWindow_drawText(window, sprite->text_score, NULL);
    sfRenderWindow_display(window);
}

void display_loose(sprite_t *sprite)
{
    char *text = cat("you have loose wave : ", int_to_string(sprite->vague));

    sfText_setString(sprite->text_loose, text);
    sfText_setFont(sprite->text_loose, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_loose, 100 * sprite->hight / 1920);
    sfText_setColor(sprite->text_loose, sfRed);
    sfText_setPosition(sprite->text_loose, (sfVector2f){croix(1920 / 5, 'l'\
    , sprite), croix(1080 / 3, 'h', sprite)});
}

void display_win(sprite_t *sprite)
{
    char *text = "you have win";

    sfText_setString(sprite->text_loose, text);
    sfText_setFont(sprite->text_loose, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_loose, 100 * sprite->hight / 1920);
    sfText_setColor(sprite->text_loose, sfRed);
    sfText_setPosition(sprite->text_loose, (sfVector2f){croix(1920 / 5, 'l'\
    , sprite), croix(1080 / 3, 'h', sprite)});
}