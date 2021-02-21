/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void display_best_score_one(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[0], " : "), sprite->all_score[1]);

    sfText_setString(sprite->text_best_score_one, text);
    sfText_setFont(sprite->text_best_score_one, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_one, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_one, sfRed);
    sfText_setPosition(sprite->text_best_score_one, (sfVector2f)\
    {croix(453, 'l', sprite), croix(163, 'h', sprite)});
}

void display_best_score_two(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[2], " : "), sprite->all_score[3]);

    sfText_setString(sprite->text_best_score_two, text);
    sfText_setFont(sprite->text_best_score_two, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_two, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_two, sfRed);
    sfText_setPosition(sprite->text_best_score_two, (sfVector2f)\
    {croix(453, 'l', sprite), croix(360, 'h', sprite)});
}

void display_best_score_tree(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[4], " : "), sprite->all_score[5]);

    sfText_setString(sprite->text_best_score_tree, text);
    sfText_setFont(sprite->text_best_score_tree, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_tree, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_tree, sfRed);
    sfText_setPosition(sprite->text_best_score_tree, (sfVector2f)\
    {croix(453, 'l', sprite), croix(543, 'h', sprite)});
}

void display_best_score_four(sprite_t *sprite)
{
    char *text = cat(cat(sprite->all_score[6], " : "), sprite->all_score[7]);

    sfText_setString(sprite->text_best_score_four, text);
    sfText_setFont(sprite->text_best_score_four, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_best_score_four, 30 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_best_score_four, sfRed);
    sfText_setPosition(sprite->text_best_score_four, (sfVector2f)\
    {croix(931, 'l', sprite), croix(163, 'h', sprite)});
}