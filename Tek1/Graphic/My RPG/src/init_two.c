/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_particules
*/

#include "rpg.h"

game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect,
enum BACK_R_s type);

void set_int_seconds_quests(scd_quest_t *quest)
{
    quest->nb_win = 0;
    quest->nb_kills = 0;

    quest->pos1 = (sfVector2f) {50, 300};
    quest->pos2 = (sfVector2f) {1600, 300};
    quest->pos3 = quest->pos2;
    for (int i = 0; i < 3; i++)
        quest->text[i].size = 20;
    quest->text[0].pos.x = quest->pos1.x + 30;
    quest->text[0].pos.y = quest->pos1.y + 70;

    quest->text[1].pos.x = quest->pos2.x + 30;
    quest->text[1].pos.y = quest->pos2.y + 70;

    quest->text[2].pos.x = quest->pos2.x + 30;
    quest->text[2].pos.y = quest->pos2.y + 70;
}

void set_seconds_quests(scd_quest_t *quest)
{
    char path[] = "assets/fonts/good_font.ttf";
    quest->text = malloc(sizeof(*quest->text) * 3);
    quest->sprite = sfSprite_create();
    quest->texture = sfTexture_createFromFile("./assets/sprites/scd_quest.png"\
    , NULL);
    sfSprite_setTexture(quest->sprite, quest->texture, sfTrue);

    set_int_seconds_quests(quest);
    make_text(&quest->text[0], "  Win 3 fights\n\nto unlock a heal\n\n      \
spell\n\n\n\n  fights won : ", path);
    make_text(&quest->text[1], " Kill 15 ennemies\n\nto unlock a speed\n\n  \
    spell\n\n\n\n     ennemies\n\n    killed : ", path);
    make_text(&quest->text[2], " Kill 30 ennemies\n\n   to unlock a\n\n black \
hole  spell\n\n\n\n     ennemies\n\n    killed : ", path);
}

void set_basics_for_fight(fight_t *fight, char *path, sfIntRect rect,
sfVector2f pos)
{
    fight->player.player_texture = sfTexture_createFromFile(path, NULL);
    fight->player.player = sfSprite_create();
    fight->player.rect = rect;
    fight->player.pos = pos;
    fight->player.life = 100;
    fight->player.weapon = SPELL_ONE;
    fight->player.clock.clock = sfClock_create();
    fight->player.clock2.clock = sfClock_create();
    sfSprite_setOrigin(fight->player.player, (sfVector2f) {32, 32});
    sfSprite_setTexture(fight->player.player, fight->player.player_texture,
    sfTrue);
    sfSprite_setTextureRect(fight->player.player, fight->player.rect);
    sfSprite_setPosition(fight->player.player, fight->player.pos);
    fight->nb_enn = 3;
    fight->max_enn = 5;
}

void set_enn2(ennemies_t *enn)
{
    enn->rect.width = 50;
    enn->rect.height = 70;
    enn->rect.top = 6;
    enn->life = 100;
    enn->velocity = generate_random(50, 100) / 10;
    enn->velocity /= 10;
    enn->tmp = 0;
    enn->in_live = 1;
    enn->buttons = malloc(sizeof(game_obj_t) * 2);
    enn->buttons[0] = create_object_fight("assets/sprites/red_enn_life.png",
    (sfVector2f){40, 40}, (sfIntRect){0, 0, 102, 14}, BACK);
    enn->buttons[1] = create_object_fight("assets/sprites/green_enn_life.png",
    (sfVector2f){40, 40}, (sfIntRect){0, 0, 102, 14}, BACK);
}