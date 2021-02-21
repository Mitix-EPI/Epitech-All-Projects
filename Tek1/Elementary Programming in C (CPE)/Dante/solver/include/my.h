/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes
*/

#include "my_printf.h"
#include <stdio.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup (int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char * my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase (char *str);
char *my_strlowcase (char *str);
char *my_strcapitalize (char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const * str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_strlen2(char *str);
int fs_open_file(char const *filepath);
void my_print_char(va_list ap, int, char, int *);
void my_print_nbr(va_list ap, int, char, int *);
void my_print_str(va_list ap, int, char, int *);
void my_print_unsigned(va_list ap, int, char, int *);
void my_print_octal(va_list ap, int, char, int *);
void my_print_hexa(va_list ap, int, char, int *);
void my_print_hexa_capitalize(va_list ap, int, char, int *);
void my_print_pointer_adress(va_list ap, int, char, int *);
void my_print_binary(va_list ap, int test, char thing, int *n);
void my_print_show_char(va_list ap, int test, char thing, int *n);
void my_print_len(va_list ap, int test, char thing, int *n);
void my_print_nb_error(va_list ap, int test, char thing, int *n);
void my_print_error(va_list ap, int test, char thing, int *n);
int my_printf(char const *format, ...);
char **my_str_to_word_array(char const *str, char separator);
char *my_super_str_cat(char *s1, char *s2);
char *get_next_line(int fd);
int draw_map(char **map);
char *receive(void);
int get_enemy_pid(int pid);
void send(int a, int b);
int is_hit(char ***map, char ***enemy_map, char *enemy_move, int turn);
int in_game(char **map, char **enemy_map);
int get_winner(int i);