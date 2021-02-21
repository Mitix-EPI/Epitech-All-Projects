/*
** EPITECH PROJECT, 2019
** richard.h
** File description:
** h file for rpg
*/

#ifndef RICHARD_H
#define RICHARD_H

typedef enum BACK_R_s{
    SIDONIA,
    PLAY,
    CONTINUE,
    OPTIONS,
    QUIT,
    FPS,
    SOUND,
    BACK,
    PLUS_FPS,
    MINUS_FPS,
    MUSIC,
    PLUS_MUSIC,
    MINUS_MUSIC,
    EFECT,
    PLUS_EFFECT,
    MINUS_EFFECT,
    BACKGROUND,
    TMP,
    PAUSE,
    SAVE,
    LEVEL
} BACK_R_t;

typedef struct text_R_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    int size;
    char *str;
    enum BACK_R_s type;
} text_R_t;

typedef struct game_obj_R_s {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    enum BACK_R_s type;
} game_obj_R_t;

typedef struct clock_R_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} clock_R_t;

typedef struct color_text_s {
    int size;
    sfColor color;
    sfVector2f pos;
} color_text_t;

#endif