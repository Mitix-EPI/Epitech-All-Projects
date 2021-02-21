/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_boss
*/

#include "rpg.h"

static const attack_t attacks[] = {
    {attack_1},
    {attack_2},
    {attack_3}
};

void boss_attack(fight_t *fight, float *max)
{
    static int i = 0;
    int r = 0;
    static sfClock *clock = NULL;
    sfTime time;
    float seconds = 0;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000;
    for (int i = 0; i < 3; i += 1)
        r += fight->boss_spell[i].activated;
    if (r == 0 && seconds > 3) {
        i = generate_random(0, 2);
        sfClock_restart(clock);
        fight->boss_spell[i].activated = 1;
        fight->boss_spell[i].rect.left = 0;
    } else
        attacks[i].attack(fight, max);
}

ennemies_t *init_boss(void)
{
    ennemies_t *obj = malloc(sizeof(ennemies_t));

    obj->enn = sfSprite_create();
    obj->enn_texture =
    sfTexture_createFromFile("assets/sprites/boss/boss.png", NULL);
    obj->clock.clock = sfClock_create();
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {0, 0, 800, 600};
    obj->velocity = 0.8;
    obj->in_live = 1;
    obj->life = 8000;
    sfSprite_setTexture(obj->enn, obj->enn_texture, sfTrue);
    sfSprite_setPosition(obj->enn, obj->pos);
    sfSprite_setTextureRect(obj->enn, obj->rect);
    sfSprite_setOrigin(obj->enn, (sfVector2f)
    {obj->rect.left + (obj->rect.width / 2),
    obj->rect.top + (obj->rect.height / 2)});
    return (obj);
}

spell_t *init_boss_spell(void)
{
    spell_t *obj = malloc(sizeof(spell_t) * 3);

    for (int i = 0; i < 3; i += 1) {
        obj[i].sprite = sfSprite_create();
        obj[i].texture = sfTexture_createFromFile(
        "assets/sprites/boss/spells.png", NULL);
        obj[i].clock = sfClock_create();
        sfSprite_setTexture(obj[i].sprite, obj[i].texture, sfFalse);
        obj[i].rect = (sfIntRect) {0, 192 * i, 192, 192};
        sfSprite_setOrigin(obj[i].sprite, (sfVector2f) {96, 96});
        if (i == 2)
            obj[i].rect.top = 5 * 192;
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
    return (obj);
}