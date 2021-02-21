/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** mattis
*/

#ifndef MATTIS2_H_
#define MATTIS2_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE 4
#endif

typedef struct data_s
{
    long pid;
    long catch_number;
    char **board;
    char **enn_board;
    char **pos_map;
}data_t;

data_t data;

//my_str_to_word_array.c
int count_malloc(char const *cache);
char *my_get_str_word(char const *str, int *n, int char_max);
int my_nb_str(char const *str);
int set_char_max(char const *str, int length);
char **my_str_to_word_array(char const *str);

//game_loop_player2.c
char *build_coord(char letter, char nb);
void game_loop_player2(void);

//win_loose.c
int condition_loose1(int not_loose, int i, int x, int y);
int condition_loose2(int not_loose, int i, int x, int y);
int check_loose(void);
int win_loose(void);
int wait_win_loose(void);

//main_player1.c
int check_touch(char *str);
int receive_hit_missed(char *str);
void connection_player1(void);
void sets(char *path);
int main_player_one(char **av);

//my_strlen.c
int my_strlen(char const *str);
int my_strlen2(char const *str);

//actions_signals.c
void connection_ennemy_validated(int sig, siginfo_t *siginfo, void *context);
void catch_siguser1(int sig, siginfo_t *siginfo, void *context);
void catch_siguser2(int sig, siginfo_t *siginfo, void *context);
void connection_validated(int sig);

//my_getnbr.c
int my_isnumb(char const c);
int my_getnbr(char const *str);

//create_empty_map.c
void add_left_board(char **map);
void add_top_board(char **map);
void add_points(char **map);
char **create_empty_map(void);

//my_str_isnum.c
int my_char_isnum(char c);

//my_putstr.c
int my_putstr(char const *str);

//my_strcmp.c
int my_count(char const *s);
int my_strcmp(char const *s1, char const *s2);

//checks.c
int condition1(char *line, char *char_pos);
int condition2(char *line, char *char_pos);
int check_if_it_touches_the_player(char *char_pos);
int check_lenght_boat(char **map);
int check_file(char **map);

//my_put_nbr.c
int my_put_nbr(int nb);

//game_loop_player1.c
void print_board(void);
char *check_input(void);
void game_loop_player1(void);
void str_to_signal(char *str);

//get_next_line.c
char *my_realloc(char *str, int n);
char *ending_choice(char *msg, int i, int rd, int *idx);
char *buff_size_alloc(int *msg_size, char *msg, char *buff, int i);
int reader(int *rd, int *idx, int fd, char *buff);
char *get_next_line(int fd);

//main_player2.c
int connection_player2(char **av);
void fill_the_struct_1(struct sigaction *act);
char *translater(void);
void send_hit_or_missed(char *coord);
int main_player_two(char **av);

//main.c
int print_help(void);
int check_map(char **map);
int rigor_map(char *path);
int rigor(int ac, char **av);
int main(int ac, char **av);

//my_str_isalpha.c
int my_str_isalpha(char const *str);
int my_char_isalpha(char c);

//update_map.c
void update_board(char **board, char *coord, int i);

//open_pos.c
int count_line(char *str);
int count_charac(char *str, int index);
char **open_pos(char *str);

//main_navy.c
int main_navy(int ac, char **av);

//create_fill_map.c
void put_line_in_map(char **map, char *str);
char **create_fill_map(char *path);

#endif /* !MATTIS2_H_ */