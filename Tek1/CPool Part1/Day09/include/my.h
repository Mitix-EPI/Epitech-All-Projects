/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** prototypes
*/

#ifndef MY_H
#define MY_H
#endif

#include <unistd.h>
#include <stdio.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup1(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putst(char const *str);
int count_char(char *str);
char *put_str_into_str(char *str, char *reverse);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
int my_count_str(char const *dest);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str);
int my_putstr(char const *str);
void condition_majuscule(char *str, int i);
int my_count_str1(char const *dest);
int my_count1(char const *to_find);
int my_show_param_array(struct info_param const *par);
int my_show_word_array(char * const *tab);
int count_my_all_charac_2(char * const *tab);
void print_str_show_word(char *str);
int count_malloc(char const *cache);
char *my_get_str_word(char const *str, int *n, int char_max);
int my_nb_str(char const *str);
