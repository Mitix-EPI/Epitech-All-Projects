/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** creates_one
*/

#include "rpg.h"

void create_and_set(sfSprite *sprite, sfTexture *texture, char *path)
{
    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
}

void create_backgrounds_end_script(end_script_t *end)
{
    end->bg = sfSprite_create();
    end->bg_t = sfTexture_createFromFile("assets/sprites/end/bg.png", NULL);
    sfSprite_setTexture(end->bg, end->bg_t, sfTrue);
    sfSprite_setScale(end->bg, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(end->bg, (sfVector2f) {170, 35});

    end->bg2 = sfSprite_create();
    end->bg2_t = sfTexture_createFromFile("assets/sprites/end/bg_2.png", NULL);
    sfSprite_setTexture(end->bg2, end->bg2_t, sfTrue);
    sfSprite_setScale(end->bg2, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(end->bg2, (sfVector2f) {170, 35});
}

void create_msg_and_txt_end_script(end_script_t *end)
{
    char path[] = "assets/fonts/good_font.ttf";

    end->msg = sfSprite_create();
    end->msg_t = sfTexture_createFromFile("assets/sprites/end/msg.png", NULL);
    sfSprite_setTexture(end->msg, end->msg_t, sfTrue);
    end->msg_rect = (sfIntRect) {0, 0, 1920, 1080};
    sfSprite_setTextureRect(end->msg, end->msg_rect);
    sfSprite_setScale(end->msg, (sfVector2f) {0.7, 0.7});
    sfSprite_setPosition(end->msg, (sfVector2f) {270, 350});

    end->text = malloc(sizeof(*end->text));
    end->text->pos = (sfVector2f) {520, 570};
    end->text->size = 20;
    make_text(end->text, "Thanks for playing\n\n\n\t\t\t\t\tCreated by \
Richard Depierre, Alexandre Juan, Rafik Merzouk and Tom Seiguin", path);
    sfText_setCharacterSize(end->text->text, 20);
}

void create_gf_and_circle(end_script_t *end)
{
    end->gf = sfSprite_create();
    end->gf_t = sfTexture_createFromFile("assets/sprites/end/girl.png", NULL);
    sfSprite_setTexture(end->gf, end->gf_t, sfTrue);
    end->gf_rect = (sfIntRect) {50, 0, 50, 73};
    sfSprite_setTextureRect(end->gf, end->gf_rect);

    end->cinematic = sfCircleShape_create();
    sfCircleShape_setPosition(end->cinematic, (sfVector2f) {960, 750});
    end->cinematic_size = (sfVector2f) {0, 0};
    end->cinematic_radius = 1;
    sfCircleShape_setOrigin(end->cinematic, (sfVector2f) {1, 1});
    sfCircleShape_setRadius(end->cinematic, end->cinematic_radius);
    sfCircleShape_setFillColor(end->cinematic, sfBlack);
    sfCircleShape_setScale(end->cinematic, end->cinematic_size);
}

void create_arrow(quest_t *quest)
{
    char path[] = "assets/sprites/arrow.png";
    sfVector2f pos = {935, 950};

    quest->arrow = sfSprite_create();
    quest->arr_t = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(quest->arrow, quest->arr_t, sfTrue);
    sfSprite_setPosition(quest->arrow, pos);
    sfSprite_setOrigin(quest->arrow, (sfVector2f) {165, 170});
    sfSprite_setScale(quest->arrow, (sfVector2f) {0.45, 0.45});
}
