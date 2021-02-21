/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void display_best_score_five(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[8], " : "), sprite->all_score[9]);

    sfText_setString(sprite->text_best_score_five, text);
    sfText_setFont(sprite->text_best_score_five, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_five, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_five, sfRed);
    sfText_setPosition(sprite->text_best_score_five, (sfVector2f)\
    {croix(931, 'l', sprite), croix(360, 'h', sprite)});
}

void display_best_score_six(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[10], " : "), sprite->all_score[11]);

    sfText_setString(sprite->text_best_score_six, text);
    sfText_setFont(sprite->text_best_score_six, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_six, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_six, sfRed);
    sfText_setPosition(sprite->text_best_score_six, (sfVector2f)\
    {croix(931, 'l', sprite), croix(543, 'h', sprite)});
}

void display_best_score_seven(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[12], " : "), sprite->all_score[13]);

    sfText_setString(sprite->text_best_score_seven, text);
    sfText_setFont(sprite->text_best_score_seven, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_seven, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_seven, sfRed);
    sfText_setPosition(sprite->text_best_score_seven, (sfVector2f)\
    {croix(1426, 'l', sprite), croix(163, 'h', sprite)});
}

void display_best_score_height(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[14], " : "), sprite->all_score[15]);

    sfText_setString(sprite->text_best_score_height, text);
    sfText_setFont(sprite->text_best_score_height, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_height, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_height, sfRed);
    sfText_setPosition(sprite->text_best_score_height, (sfVector2f)\
    {croix(1426, 'l', sprite), croix(360, 'h', sprite)});
}

void display_best_score_nine(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[16], " : "), sprite->all_score[17]);

    sfText_setString(sprite->text_best_score_nine, text);
    sfText_setFont(sprite->text_best_score_nine, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_nine, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_nine, sfRed);
    sfText_setPosition(sprite->text_best_score_nine, (sfVector2f)\
    {croix(1426, 'l', sprite), croix(543, 'h', sprite)});
}