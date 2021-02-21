/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** musics
*/

#include "rpg.h"

void set_volume(rpg_t *rpg)
{
    sfSound_setVolume(rpg->snd_win, rpg->music_volume);
    sfSound_setVolume(rpg->snd_loose, rpg->music_volume);
    sfSound_setVolume(rpg->snd_clic, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_menu, rpg->music_volume);
    sfSound_setVolume(rpg->snd_tuto, rpg->music_volume);
    sfSound_setVolume(rpg->snd_main_music, rpg->music_volume);
    sfSound_setVolume(rpg->snd_main_music_fight, rpg->music_volume);
    sfSound_setVolume(rpg->snd_fireball, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_shield, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_black_hole, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_heal, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_speed, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_win_fight, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_end, rpg->music_volume);
    sfSound_setVolume(rpg->snd_boss, rpg->music_volume);
}

void stop_all_music(rpg_t *rpg)
{
    sfSound_stop(rpg->snd_win);
    sfSound_stop(rpg->snd_loose);
    sfSound_stop(rpg->snd_clic);
    sfSound_stop(rpg->snd_menu);
    sfSound_stop(rpg->snd_tuto);
    sfSound_stop(rpg->snd_main_music);
    sfSound_stop(rpg->snd_main_music_fight);
    sfSound_stop(rpg->snd_fireball);
    sfSound_stop(rpg->snd_shield);
    sfSound_stop(rpg->snd_black_hole);
    sfSound_stop(rpg->snd_heal);
    sfSound_stop(rpg->snd_speed);
    sfSound_stop(rpg->snd_win_fight);
    sfSound_stop(rpg->snd_end);
    sfSound_stop(rpg->snd_boss);
}

void set_music_loop(rpg_t *rpg)
{
    sfSound_setLoop(rpg->snd_menu, sfTrue);
    sfSound_setLoop(rpg->snd_tuto, sfTrue);
    sfSound_setLoop(rpg->snd_main_music, sfTrue);
    sfSound_setLoop(rpg->snd_main_music_fight, sfTrue);
    sfSound_setLoop(rpg->snd_boss, sfTrue);
}

sfSound *create_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(sound, soundbuffer);
    return (sound);
}

void set_musics(rpg_t *rpg)
{
    rpg->snd_win = create_sound("assets/music/sound_effect_win.ogg");
    rpg->snd_loose = create_sound("assets/music/music_death.ogg");
    rpg->snd_clic = create_sound("assets/music/sound_effect_click.ogg");
    rpg->snd_menu = create_sound("assets/music/music_menu.ogg");
    rpg->snd_tuto = create_sound("assets/music/music_tuto.ogg");
    rpg->snd_main_music = create_sound("assets/music/music_quest.ogg");
    rpg->snd_main_music_fight = create_sound("assets/music/music_fight.ogg");
    rpg->snd_fireball = create_sound("assets/music/sound_effect_fire.ogg");
    rpg->snd_shield = create_sound("assets/music/sound_effect_shield.ogg");
    rpg->snd_black_hole =
    create_sound("assets/music/sound_effect_black_hole.ogg");
    rpg->snd_heal = create_sound("assets/music/sound_effect_heal.ogg");
    rpg->snd_speed = create_sound("assets/music/sound_effect_speed.ogg");
    rpg->snd_win_fight =
    create_sound("assets/music/sound_effect_win_fight.ogg");
    rpg->snd_end = create_sound("assets/music/end.ogg");
    rpg->snd_boss = create_sound("assets/music/music_boss.ogg");
    set_music_loop(rpg);
    set_volume(rpg);
    sfSound_play(rpg->snd_menu);
}
