/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_scores
*/

#include "../my_tower.h"

void display_best_scores(sprite_t *sprite, sfRenderWindow *window)
{
    display_best_score_one(sprite);
    display_best_score_two(sprite);
    display_best_score_tree(sprite);
    display_best_score_four(sprite);
    display_best_score_five(sprite);
    display_best_score_six(sprite);
    display_best_score_seven(sprite);
    display_best_score_height(sprite);
    display_best_score_nine(sprite);
    sfRenderWindow_drawText(window, sprite->text_best_score_one, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_two, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_tree, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_four, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_five, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_six, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_seven, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_height, NULL);
    sfRenderWindow_drawText(window, sprite->text_best_score_nine, NULL);
}