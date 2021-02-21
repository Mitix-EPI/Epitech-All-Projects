/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** update_map
*/

#include "../my_tower.h"

void update_map(sprite_t *sprite)
{
    sfTexture *texture;
    if (sprite->level == 1) {
        texture = sfTexture_createFromFile("sprite/map1.png", NULL);
    } else if (sprite->level == 2) {
        texture = sfTexture_createFromFile("sprite/map2.png", NULL);
    } else {
        texture = sfTexture_createFromFile("sprite/map3.png", NULL);
    }
    sfSprite_setTexture(sprite->map, texture, sfTrue);
}

void update_map_(sprite_t *sprite)
{
    if (sprite->level == 1)
        sprite->map_ = my_str_to_word_array(map_reader\
    ("map/edited_level1_sized.txt", 2340));
    if (sprite->level == 2)
        sprite->map_ = my_str_to_word_array(map_reader\
    ("map/edited_level2_sized.txt", 2340));
    if (sprite->level == 3)
        sprite->map_ = my_str_to_word_array(map_reader\
    ("map/edited_level3_sized.txt", 2340));
}