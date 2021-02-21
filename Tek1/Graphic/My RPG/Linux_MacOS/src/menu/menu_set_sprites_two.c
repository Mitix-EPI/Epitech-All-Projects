/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "my.h"

char *int_to_char(int nb)
{
    char *res;
    int count = 0;

    for (int tmp = nb; tmp > 0; tmp /= 10)
        count += 1;
    res = malloc(sizeof(char) * (count + 1));
    res[count--] = '\0';
    for (int tmp = nb; tmp > 0; tmp /= 10)
        res[count--] = tmp % 10 + '0';
    return (res);
}

game_obj_R_t modify_from_type(game_obj_R_t object, enum BACK_R_s type)
{
    if (type == SIDONIA)
        sfSprite_setScale(object.sprite, (sfVector2f){1.5, 1.5});
    if (type == PLUS_FPS || type == MINUS_FPS ||
    type == PLUS_MUSIC || type == MINUS_MUSIC ||
    type == PLUS_EFFECT || type == MINUS_EFFECT)
        sfSprite_setScale(object.sprite, (sfVector2f){0.4, 0.4});
    if ((type >= 1 && type <= 7) || type == MUSIC || type == EFECT )
        sfSprite_setScale(object.sprite, (sfVector2f){1.4, 1.4});
    if (type == BACKGROUND)
        sfSprite_setScale(object.sprite, (sfVector2f){1.9, 1.9});
    return (object);
}

game_obj_R_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type)
{
    game_obj_R_t object;

    object.texture = sfTexture_createFromFile(filepath, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setPosition(object.sprite, pos);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, rect);
    object.rect = rect;
    object.pos = pos;
    object.type = type;
    return (modify_from_type(object, type));
}

void make_text(text_R_t *text, char *str, char *file)
{
    text->font = sfFont_createFromFile(file);
    text->text = sfText_create();
    text->str = my_strcpy(str);
    sfText_setString(text->text, str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setPosition(text->text, text->pos);
    sfText_setColor(text->text, sfWhite);
}

void malloc_everything(rpg_t *rpg)
{
    rpg->clock = malloc(sizeof(*rpg->clock) * 3);
    rpg->spawn = malloc(sizeof(*rpg->clock));
    rpg->spawn->clock = sfClock_create();
    rpg->menu = malloc(sizeof(*rpg->menu) * 22);
    rpg->text = malloc(sizeof(*rpg->text) * 24);
}