/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

typedef struct sokoban_s {
    int ch;
    int width;
    char **stra;
    char **s_mod;
    int x;
    int y;
    int **o_index;
    int nb_o;
}sokoban_t;

//my_str_to_word_array.c
char **my_str_to_word_array(char const *str);
int set_char_max(char *str, int length);
int my_nb_str(char const *str);
char *my_get_str_word(char const *str, int *n, int char_max);
int count_malloc(char const *cache);

//move.c
void move_left(sokoban_t *s);
void move_up(sokoban_t *s);
void move_down(sokoban_t *s);
void move_right(sokoban_t *s);
int move_player(sokoban_t *s);

//checks.c
int check(int argc, char *argv, sokoban_t *s);
int check_0(sokoban_t *s);
void check_pos_o(sokoban_t *s);
void check_sh(sokoban_t *s, char *map);

//finds.c
void find_o(sokoban_t *s);
void find_p(sokoban_t *s);
int find_hashtag(sokoban_t *s);

//prints.c
void print_map(sokoban_t *s);
int print_usage(char **argv, sokoban_t *s);
void my_disp(sokoban_t *s);

//main_sokoban.c
int main_sokoban(int argc, char **argv, sokoban_t *s);
int play_sokoban(sokoban_t *s, char *map);
char *map_reader(char *map, long size);
int my_strlen(char const *str);

#endif /* !MY_H_ */
