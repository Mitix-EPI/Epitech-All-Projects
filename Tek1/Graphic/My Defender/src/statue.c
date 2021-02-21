/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void display_name(sprite_t *sprite)
{
    sfVector2f menu_position = {sprite->hight / 6, sprite->weidth / \
    2 - sprite->weidth / 5};

    sfText_setString(sprite->text_menu, sprite->name);
    sfText_setFont(sprite->text_menu, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_menu, 120 * sprite->hight / 1920);
    sfText_setColor(sprite->text_menu, sfRed);
    sfText_setPosition(sprite->text_menu, menu_position);
}

void enter_name(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    display_name(sprite);
    sfRenderWindow_drawText(window, sprite->text_menu, NULL);
    sfRenderWindow_display(window);
}

void draw_option(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->back_opt, NULL);
    sfRenderWindow_drawSprite(window, sprite->sound_volume, NULL);
    sfSprite_setScale(sprite->back_opt, (sfVector2f){1 * sprite->hight / 1920\
    , 1 * sprite->weidth / 1080});
    sfSprite_setScale(sprite->sound_volume, (sfVector2f){2 * sprite->hight \
    / 1920, 2 * sprite->weidth / 1080});
    sfSprite_setPosition( sprite->sound_volume, (sfVector2f){700 * \
    sprite->hight / 1920, 620 * sprite->weidth / 1080});
    sfSprite_setTextureRect(sprite->sound_volume, (sfIntRect){sprite->rep \
    * 32, 0, 193, 32});
    sfRenderWindow_display(window);
}

void draw_statue(sfRenderWindow *window, sprite_t *sprite)
{
    if (sprite->statue == 0)
        draw_menu(window, sprite);
    if (sprite->statue == 1)
        draw_option(window, sprite);
    if (sprite->statue == 2)
        enter_name(window, sprite);
    if (sprite->statue == 3)
        game(window, sprite);
    if (sprite->statue == 4)
        loose(window, sprite);
    if (sprite->statue == 5)
        win(window, sprite);
    if (sprite->statue == 6)
        choose_lvl(window, sprite);
}