/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spells
*/

#include "rpg.h"

void set_txt_cooldown(text_R_t *txt, spells_names_t type)
{
    txt->size = 30;
    txt->pos.x = ((type - 1) * 110) + 726;
    txt->pos.y = 990;
    make_text(txt, "", "assets/fonts/good_font.ttf");
    txt->str = NULL;
}

void init_fireball_shield(spell_t *spell, spells_names_t type,  sfIntRect rect)
{
    spell->tmp = 0;
    spell->tmp2 = 0;
    if (type == FIREBALL) {
        spell->damage = 2;
        spell->protection = 0;
        spell->sec = 1;
    }
    if (type == SHIELD) {
        spell->protection = 10;
        spell->damage = 1;
        sfSprite_setOrigin(spell->sprite, (sfVector2f) {27, rect.height / 2});
        sfSprite_setScale(spell->sprite, (sfVector2f) {1.7, 1.7});
        spell->sec = 8;
    }
    init_health_speeds(spell, type, rect);
    init_black_hole(spell, type, rect);
}

spell_t init_spell(char *path, spells_names_t type, sfIntRect rect)
{
    spell_t spell;

    spell.sprite = sfSprite_create();
    spell.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(spell.sprite, spell.texture, sfTrue);
    sfSprite_setPosition(spell.sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(spell.sprite, (sfVector2f) {1, 1});
    spell.rect = rect;
    sfSprite_setTextureRect(spell.sprite, spell.rect);
    sfSprite_setOrigin(spell.sprite, (sfVector2f) {28, 15.5});
    spell.velocity = 0.5;
    spell.clock = sfClock_create();
    spell.clock_cd.clock = sfClock_create();
    spell.type = type;
    set_txt_cooldown(&spell.text, type);
    init_fireball_shield(&spell, type, rect);
    spell.activated = 0;
    return (spell);
}
