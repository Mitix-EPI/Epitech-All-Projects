/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#include "../include/my.h"

int file_empty(tetrimino_t *tetrimino, tetris_t *tetris)
{
    tetrimino->type = NULL;
    if (tetris->debug == 1)
        my_printf("Error\n");
    return (0);
}

int display_after_name(char *str, tetrimino_t *tetrimino, tetris_t *tetris)
{
    int fd = open(str, O_RDONLY);
    struct stat sb;

    stat(str, &sb);
    if (sb.st_size < 3)
        return (file_empty(tetrimino, tetris));
    char txt[sb.st_size];
    char **map = NULL;
    read(fd, txt, sb.st_size);
    txt[sb.st_size] = 0;
    map = my_str_to_word_array(txt);
    if (handle_color(map, tetrimino) &&\
    handle_size(map, tetris, tetrimino)) {
    } else {
        tetrimino->type = NULL;
        if (tetris->debug == 1)
            my_printf("Error\n");
    }
    return (0);
}

void display_info_files(char **name_files, tetris_t *tetris)
{
    char *str = NULL;
    char *name = NULL;

    for (int i = 0; name_files[i] != NULL; i++) {
        name = remove_dot_tetrimino(name_files[i]);
        if (tetris->debug == 1)
            my_printf("Tetriminos : Name %s : ", name);
        str = my_strcat("tetriminos/", name_files[i]);
        display_after_name(str, &tetris->tetrimino[i], tetris);
    }
    free(name);
    free(str);
}

void display_rules(tetris_t *tetris)
{
    first_part(tetris);
    second_part(tetris);
}

int display_debug_mode(tetris_t *tetris)
{
    if (tetris->debug == 1) {
        my_printf("*** DEBUG MODE ***\n");
        display_rules(tetris);
    }
    if (check_tetrimino(tetris))
        return (84);
    if (tetris->debug == 1) {
        my_printf("Press any key to start Tetris\n");
        mygetch();
    }
    return (0);
}