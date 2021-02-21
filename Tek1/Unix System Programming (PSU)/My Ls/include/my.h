/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#define majorez(x) ((x >> 8) & 0x7FF)
#define minorez(x) (x & 0xFF)

#define MAJOR(x) ((long)majorez(x))
#define MINOR(x) ((long)minorez(x))

typedef struct ls_s
{
    int order;
    char *name;
    char *perms;
    char *usr;
    int size;
    char *date;
    char *hour;
    char type;
}ls_t;

//flags.c
int good_flags(char c, int *list_flag);
int check_flags(int ac, char **av, int *list_flags);
int check_only_flags(int ac, char **av);
int condition_print_flag(char *path, char *name);
int print_flag(int *flags, struct stat my_stat, char *path, char *name);

//l_flags.c
void print_date(struct stat my_stat);
void end_print_total(int total, DIR *mydir);
int condition_total(char *name, int total);
void print_total(char *path);
void l_flags(struct stat my_stat);

//l_flags2.c
void print_first_perm(struct stat my_stat);
void print_permissions(struct stat my_stat);
void print_hard_link(struct stat my_stat);
void print_owner(struct stat my_stat);
void print_size(struct stat my_stat);

//ls_args.c
int boolen_condition(char *name);
int if_else_ls_args(int *flags, char **av, int count, struct stat *mystat);
int ls_args(int ac, char **av, int *flags);

//ls_folder.c
int end_ls_folder(int *flags, DIR *mydir);
int condition_ls_folder(int *flags, char **av, int count);
int ls_folder(int *flags, char **av, int count, struct stat *mystat);

//my_ls.c
int ls_root(char **av, int *flags);
int d_ls_root(char **av, int *flags);
int my_ls(int ac, char **av);

//my_put_nbr.c
int my_put_nbr(int nb);

//my_putstr.c
int my_putstr(char const *str);

//my_strcat.c
int my_count_str(char const *dest);
char *my_strcat(char *dest, char const *src);

//name.c
int my_strlen(char *str);
char *name_file(char *str);

//print.c
void print_name(char *str);
int print_error(void);

//t_flag.c
void score_condition(int mtime, int i, int *score, int *idx);
char *newest_first(int nb_file, char **names_files, char *path);
void end_t_flag(char **names_files, DIR *mydir, int nb_file);
void condition_t_flag(char *path, char *answer);
void t_flag(char *path, int *flags);

//t_flags2.c
int count_file(char *path);
char **set_array(int nb_file, char *path);

#endif /* !MY_H_ */
