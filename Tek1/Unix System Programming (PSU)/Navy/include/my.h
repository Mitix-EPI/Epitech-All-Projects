/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

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
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>


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

char **open_pos(char *str);

//actions_signals.c
void connection_ennemy_validated(int sig, siginfo_t *siginfo, void *context);
void catch_siguser1(int sig, siginfo_t *siginfo, void *context);
void catch_siguser2(int sig, siginfo_t *siginfo, void *context);
void connection_validated(int sig);

//my_putstr.c
int my_putstr(char const *str);

//my_strlen.c
int my_strlen(char const *str);

void game_loop_player2(void);

int my_strlen2(char const *str);

char *build_coord(char letter, char nb);

int my_char_isalpha(char c);

int my_char_isnum(char c);

char **create_fill_map(char *path);

void send_hit_or_missed(char *coord);

int receive_hit_missed(char *str);

//my_str_isalpha.c
int my_str_isalpha(char const *str);

void str_to_signal(char *str);
void sets(char *path);
char *translater(void);

void fill_the_struct_1(struct sigaction *act);

void update_board(char **board, char *coord, int i);

int win_loose(void);
int wait_win_loose(void);

int check_touch (char *str);


//main_navy.c
int main_navy(int ac, char **av);

//my_put_nbr.c
int my_put_nbr(int nb);

//my_str_to_word_array.c
char **my_str_to_word_array(char const *str);

int my_getnbr(char const *str);

char *get_next_line(int fd);

//checks.c
int check_if_it_touches_the_player(char *char_pos);

//main_player1.c
int main_player_one(char **av);

char **create_empty_map(void);

//main_player2.c
int main_player_two(char **av);
void fill_the_struct(struct sigaction *act);

//game_loop_player1.c
void print_board(void);
char *check_input(void);
void game_loop_player1(void);
void str_to_signal(char *str);

//my_strcmp.c
int my_strcmp(char const *s1, char const *s2);

int check_lenght_boat(char **map);
int check_file(char **map);


#endif /* !MY_H_ */