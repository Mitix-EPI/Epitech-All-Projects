/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** sets
*/

#include "../include/my.h"

void sets_game(game_t *game)
{
    game->endless = 0;
    game->difficulty = 2;
    sets_hero(game);
    set_score(game);
}

void sets_options(game_t *game)
{
    char *chg = "./assets/buttons/+_-.png";
    char *val = "./assets/buttons/endless.png";

    crt_txt(&game->txt[0], "IPS", (sfVector2f) {375, 200});
    crt_txt(&game->txt[1], my_itc(game->ips), (sfVector2f) {925, 200});
    crt_txt(&game->txt[2], "Volume Musique", (sfVector2f) {375, 300});
    crt_txt(&game->txt[3], my_itc(game->vol_music), (sfVector2f) {925, 300});
    crt_txt(&game->txt[4], "Volume Effets", (sfVector2f) {375, 400});
    crt_txt(&game->txt[5], my_itc(game->vol_effect), (sfVector2f) {925, 400});
    crt_txt(&game->txt[6], "Difficulte", (sfVector2f) {375, 500});
    crt_txt(&game->txt[7], my_itc(game->difficulty), (sfVector2f) {925, 500});
    crt_txt(&game->txt[8], "Sans limite", (sfVector2f) {375, 600});
    game->opts_but[1] = crt_options_buts(chg, (sfVector2f) {1075, 300}, 0);
    game->opts_but[0] = crt_options_buts(chg, (sfVector2f) {1075, 200}, 0);
    game->opts_but[2] = crt_options_buts(chg, (sfVector2f) {1075, 400}, 0);
    game->opts_but[3] = crt_options_buts(chg, (sfVector2f) {1075, 500}, 0);
    game->opts_but[4] = crt_options_buts(val, (sfVector2f) {1125, 600}, 1);
}

void sets_barriers(game_t *game, char *map)
{
    struct stat fileStat;
    stat(map, &fileStat);
    char **mapa = my_str_to_word_array(map_reader(map, fileStat.st_size));
    int i = 0;

    sfIntRect r = {0, 0, 100, 100};
    game->bars = malloc(sizeof(barriers_t) * count_charac(mapa, '1'));
    for (int y = 0, x_2 = 0; mapa[y] != NULL; y++) {
        for (int x = 0; mapa[y][x] != 'E'; x += 1, x_2 += 1)
            if (mapa[y][x] == '1') {
                game->bars[i] = crt_bar((sfVector2f) {calc(x), y * 127}, r);
                i++;
            }
        if (y == 0)
            game->end = crt_end((sfVector2f) {calc(x_2) + 400, 0});
    }
    game->limit_bar = i;
    for (int y = 0; mapa[y] != NULL; y++)
        free(mapa[y]);
    free(mapa);
}

void set_music(game_t *game)
{
    char *music_path0 = "./assets/music/main-theme.ogg";
    char *music_path1 = "./assets/music/win.ogg";
    char *music_path2 = "./assets/music/loose.ogg";
    char *music_path3 = "./assets/music/jump.ogg";
    char *music_path4 = "./assets/music/button_song.ogg";
    char *music_path5 = "./assets/music/effect.ogg";

    game->music[0] = crt_sound(music_path0);
    game->music[1] = crt_sound(music_path1);
    game->music[2] = crt_sound(music_path2);
    game->music[3] = crt_sound(music_path3);
    game->music[4] = crt_sound(music_path4);
    game->music[5] = crt_sound(music_path5);
    sfSound_setLoop(game->music[0].sound, sfTrue);
    sfSound_setVolume(game->music[0].sound, 100.f);
    game->vol_music = 100;
    game->vol_effect = 100;
    sfSound_play(game->music[0].sound);
}

void basics_sets(game_t *game, char *map)
{
    set_music(game);
    create_window(game);
    sets_parallax(game);
    sets_barriers(game, map);
    sets_game(game);
    sets_options(game);
}