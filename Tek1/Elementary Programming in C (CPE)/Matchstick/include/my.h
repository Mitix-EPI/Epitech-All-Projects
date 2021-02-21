/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
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

typedef struct matchstick_s
{
    char **board;
    int line;
    int max_matches;
    int line_selected;
    int matches_selected;
    int end_res;
}matchstick_t;

int prt_rtn(char *str);

//get.c
void get_start_info(matchstick_t *ms);

//my_print.c
void print_map(matchstick_t *ms);
void print_end_msg(int res);

//main_matchstick.c
int free_board(char **board);
int check_stick(char **board);
int get_args(int ac, char **av, matchstick_t *ms);
int main_matchstick(int ac, char **av);

//main.c
int main(int ac, char **av);

//user2.c
int check_existing_line(matchstick_t *ms, int tmp);
int check_line_selected(matchstick_t *ms, int tmp);
int check_nb_matches(matchstick_t *ms, int line);
int check_matches_selected(matchstick_t *ms, int tmp, int line);
int end_retur_n(char *str1, char *str2, char **array, int i);

//bot.c
int generate_random(int lower, int upper);
void print_ia_message(int line, int matches);
void bot_turn(matchstick_t *ms);

//create_map.c
void set_start_end(char **board, int line);
void set_matches(char **board, int line);
char **print_my_lucas(int line);

//checks.c
int checks_buff_size(char *buffer, matchstick_t *ms);
int checks_buff_max_matchsticks(char *buffer, matchstick_t *ms);

//my_put_nbr.c
int my_put_nbr(int nb);

//user.c
int loop(matchstick_t *ms, char *buff_size, char *buff_matchsticks);
int get_line_matches(matchstick_t *ms);
void print_message(int line, int matches);
void update_map(char **board, int line, int matches);
int user_turn(matchstick_t *ms);

//my_getnbr.c
int my_isnumb(char const c);
int my_getnbr(char const *str);

#endif /* !MY_H_ */