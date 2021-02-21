/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** create
*/

#include "../include/my.h"
struct barriers_s crt_bar(sfVector2f pos, sfIntRect rect)
{
    char *path = "./assets/barriers/shurikensprite2.png";
    barriers_t bar;

    bar.seconds = 0.f;
    sfVector2f scale = {0.75f, 0.75f};
    bar.pos.x = pos.x;
    bar.pos.y = pos.y;
    bar.x_origin = pos.x;
    bar.rect = rect;
    bar.sprite = sfSprite_create();
    bar.texture = sfTexture_createFromFile(path, NULL);
    bar.clck = sfClock_create();
    sfSprite_setTexture(bar.sprite, bar.texture, sfTrue);
    sfSprite_setPosition(bar.sprite, bar.pos);
    sfSprite_setScale(bar.sprite, scale);
    sfSprite_setTextureRect(bar.sprite, bar.rect);
    return (bar);
}

struct end_s crt_end(sfVector2f pos)
{
    char *path = "./assets/barriers/endsprite.png";
    end_t end;

    sfVector2f scale = {1, 1};
    end.pos.x = pos.x;
    end.pos.y = pos.y;
    end.x_origin = pos.x;
    end.seconds = 0.f;
    end.sprite = sfSprite_create();
    end.texture = sfTexture_createFromFile(path, NULL);
    end.clck = sfClock_create();
    sfSprite_setTexture(end.sprite, end.texture, sfTrue);
    sfSprite_setPosition(end.sprite, end.pos);
    sfSprite_setScale(end.sprite, scale);
    return (end);
}

struct music_s crt_sound(char *path)
{
    music_t music;
    music.sound = sfSound_create();
    music.buff = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(music.sound, music.buff);
    sfSound_setVolume(music.sound, 100.0f);
    return (music);
}

struct buttons_s crt_options_buts(char *path, sfVector2f pos, int i)
{
    buttons_t buts;

    sfIntRect rect = {0, 0, 200, 100};
    if (i == 1)
        rect.width = 100;
    buts.rct = rect;
    buts.sprt = sfSprite_create();
    buts.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(buts.sprt, buts.texture, sfTrue);
    sfSprite_setTextureRect(buts.sprt, rect);
    sfSprite_setPosition(buts.sprt, pos);
    return (buts);
}

void crt_txt(txt_t *txt, char *str, sfVector2f pos)
{
    sfFont *font = sfFont_createFromFile("./assets/Games.ttf");
    txt->text = sfText_create();
    sfText_setString(txt->text, str);
    sfText_setFont(txt->text, font);
    sfText_setCharacterSize(txt->text, 60);
    sfText_setPosition(txt->text, pos);
    sfText_setColor(txt->text, sfBlack);
}