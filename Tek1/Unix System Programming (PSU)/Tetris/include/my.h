/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_


#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Context.h>
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
#include <ncurses.h>
#include <getopt.h>
#include <termios.h>
#include <curses.h>
#include <time.h>


typedef struct tetrimino_s {
    char *name_file;
    int x;
    int y;
    int color;
    char **origin;
    char **type;
}tetrimino_t;

typedef struct first_line_s
{
    int x;
    int y;
    int z;
    int i;
}first_line_t;

typedef struct vector_s
{
    int x;
    int y;
}vector_t;

typedef struct clock_c
{
    float second;
} clock_s;

typedef struct tetris_s {
    tetrimino_t *tetrimino;
    int level;
    char *LEFT;
    int key_left;
    int key_right;
    int key_turn;
    int key_down;
    int key_quit;
    int key_pause;
    char *RIGHT;
    char *TURN;
    char *DOWN;
    char *QUIT;
    char *PAUSE;
    char *RESTART;
    int tetrimino_selected;
    char **map;
    int row;
    int col;
    char *good_tetr;
    int change;
    int id;
    int id_next;
    int hide_next;
    int quit;
    int score;
    int nb_tetriminos;
    int lines;
    double timer_level;
    double time;
    int loose;
    int debug;
    int activated_pause;
}tetris_t;

typedef struct array_s
{
    char c;
    void(*ptr)();
}array_t;

int key_bind_two(int opt, tetris_t *tetris);
void all_free(tetris_t *tetris);
char **my_put_above(char **dest, char *src);
int retry_menu(tetris_t *tetris);
int loose(tetris_t *tetris);
void update_values(tetris_t *tetris, clock_t *clockk);
void second_part(tetris_t *tetris);
void first_part(tetris_t *tetris);
int cant_go_left(char **map);
void cleanduplicate_l(tetris_t *tetris, vector_t start, vector_t tetri, int id);
void down_tetrimino(tetris_t *tetris);
void clean_duplicate(tetris_t *tetris, vector_t start, vector_t tetri, int id);
struct vector_s return_p_x_position(char **map);
void select_id_tetrimino(tetris_t *tetris);
int generate_random(int l, int r);
int check_player_touch(tetris_t *tetris);
void freeze_player(tetris_t *tetris);
void draw_player(tetris_t *tetris, WINDOW *a);
int bind_touch(tetris_t *tetris, WINDOW *a, clock_t *clockk);
void display(tetris_t *tetris, WINDOW *a, WINDOW *b, WINDOW *c);
int controls(tetris_t *tetris, char b);
void turn_tetrimino(tetris_t *tetris);
void remplace_into_map(char **map, char **tetri, vector_t old);
void clear_player(char **map);
vector_t return_y_x_max(char **map);
void display_tetriminos(tetris_t *tetris, WINDOW *a);
void display_boards(tetris_t *tetris, WINDOW *a, WINDOW *b, WINDOW *c);
void display_c_board(WINDOW *c, tetris_t *tetris);
void display_error(void);
void initialisation(tetris_t *tetris);
void fix_keys(tetris_t *tetris);
void bind_keys(char *str, int *key);
char *good_tetriminos(tetris_t *tetris);
void down_all_lines_above(char **map, int i);
char **copy_arrays(char **dest, char **src);
char **rotate_tetrimino(char **tetri);
char *fill_str(char *str, char c, int size);
int check_player_touch(tetris_t *tetris);
void down_tetrimino(tetris_t *tetris);
void clean_duplicate(tetris_t *tetris, vector_t start, vector_t tetri, int id);
void move_down(tetris_t *tetris);
void move_right(tetris_t *tetris);
void move_left(tetris_t *tetris);
struct vector_s return_p_x_position(char **map);
char **create_map(tetris_t *tetris);
void gameplay(tetris_t *tetris, WINDOW *a, clock_t *clockk);
char *my_itc(int nbr);
int check_flags(int ac, char **av);
int error_handling(int ac, char **av);
void handling_space_map(char **map);
int print_tetrimino(char **map);
int verif_size(char *str, int x);
int x_y_z_handling(char **map, first_line_t *line);
void display_info_files(char **name_files, tetris_t *tetris);
int check_tetrimino(tetris_t *tetris);
int handle_size(char **map, tetris_t *tetris, tetrimino_t *tetrimino);
int handle_color(char **map, tetrimino_t *tetrimino);
char **display_nb_files(tetris_t *tetris);
int get_row_and_col(tetris_t *tetris, char *optarg);
int colornum(int fg, int bg);
void init_colorpairs(void);
void unsetcolor(int fg, int bg);
void setcolor(int fg, int bg);
void display_tetris_name(void);
void display_t_1(void);
void display_e(void);
void display_t_2(void);
void display_r(void);
void display_i(void);
void display_s(void);
int mygetch(void);
int count_nb_files(void);
int my_strncmp(char const *s1, char const *s2, int n);
void my_putchar(char const c);
int my_printf(char const *format, ...);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_base(long long nb, char *base);
int check_if_h(char const *str);
int unsignednbr(unsigned int nb);
void my_print_color(int color);
void is_str(va_list ap);
void is_nbr(va_list ap);
void is_ptr(va_list ap);
void is_char(va_list ap);
void is_hex(va_list ap);
void is_hex_maj(va_list ap);
void is_bin(va_list ap);
void is_oct(va_list ap);
void is_notneg(va_list ap);
void is_percentage(va_list ap);
void is_array(va_list ap);
void is_int_star(va_list ap);
void is_raimbow_str(va_list ap);
int set_user_rules(int ac, char **av, tetris_t *tetris);
char *my_strdup(char const *src);
char *remove_dot_tetrimino(char *str);
int dot_tetrimino(char *str);
char *remove_spaces_at_the_end(char *str);
char *my_revstr(char *str);
char **alpha_sort(char **tab);
char **my_str_to_word_array(char const *str);
int display_debug_mode(tetris_t *tetris);
int play_tetris(tetris_t *tetris);
int tetris(int ac, char **av);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int display_help(char *av);

#endif /* !MY_H_ */
