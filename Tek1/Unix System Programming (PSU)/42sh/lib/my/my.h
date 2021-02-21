/*
** EPITECH PROJECT, 2019
** my
** File description:
** My Header
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
char *my_evil_str(char *);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_isneg(int);
int my_is_prime(int);
int my_putchar(char);
int my_put_nbr(int);
int my_put_nbr_unsigned(unsigned int);
int my_putstr(char const *);
int my_puterror(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
int my_show_word_array(char * const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
char *my_strcat2(char *, char *, int, int);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int, int);
void invert_elements(char *, int, int);
char my_edit_str(char *, int);
int check_negative(char);
int make_negative(int, int);
int array_is_sort(int *, int);
char **my_str_to_word_array(char *);
char *my_strdup(char const *);
int is_alphabetic(char);
int get_nb_words(char const *);
int get_len_word(char const *, int);
char *get_word(char const *, int);
int my_char_islower(char);
int my_char_isupper(char);
void *my_memset(char *, int, int);
char *my_charcat(char *, char const);
char *my_itoa(int);
char *my_base_to_dec(char *, char *);
char *my_dec_to_base(char *, char *);
char *my_realloc(char *, int);
int my_putnbr_base(int, char const *);
char **my_split(char const *, char);
int my_printf(char *, ...);
char *my_char_tostring(char const);
char **my_split_str(char *, char *);
char *my_str_replace(const char *str, const char *old, const char *new);
char *my_arr_join(char **arr, char *join);
void my_arr_insert(char ***arr, char *value);
int my_arr_contain(char **arr, char *value);