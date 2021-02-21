/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>


typedef struct execute_s {
    char *tmp;
    char *symb;
    int pipefd[3];
}execute_t;

execute_t exec;

typedef struct node_s {
    char *value;
    int pipes[2];
    struct node_s *left;
    struct node_s *right;
    int direction;
    char *previews;
}node_t;

typedef struct objt_struct_s
{
    char *name;
    char *txt;
    struct objt_struct_s *next;
}objt_struct_t;

//redirections.c
void execute_left_simple(char *file, node_t *tmp, char ***envs,
objt_struct_t **head);
void execute_left_double(char *file, node_t *tmp, char ***envs,
objt_struct_t **head);
void execute_right_simple(char ***args, char ***envs, node_t *tmp,
objt_struct_t **head);

//pipes.c
void execute_pipe(char ***envs, node_t *tmp, objt_struct_t **head);
void pipe_everything(char ***envs, node_t *tmp, objt_struct_t **head);

//dot_comma.c
void execute_dot_comma(node_t *tmp, char ***envs, objt_struct_t **head);
int execute_command3(node_t *tmp, char **envi, char **env,
objt_struct_t **head);

//tree.c
void printTree(node_t *tree);

//execute_arbol.c
int execute_command(node_t *tmp, char **env, objt_struct_t **head);
int execute_symb(char *str, char **envi, char **env, objt_struct_t **head);
void symb_or_command(char *str, char **envi, char **env, objt_struct_t **head);
void execute_arbol(node_t *tmp, char **envi, char **env, objt_struct_t **head);

//set_arbol.c
node_t *return_arbol(char *str);
node_t *recursive_arbol(node_t *arbol, char *str);
node_t *set_arbol(node_t *arbol, char *sym, char *str, char *tmp);
node_t *set_elem(char *sym, char *str, node_t *elem, char *tmp);

//symbols.c
char *symbol(char *str);
int search_symb(char *str, char *sym);

//separation.c
int count_str_right(char *str, int i);
char *right_separation(char *str, int i, char *sym);
char *left_separation(char *str, int i);

//chained_list2.c
objt_struct_t *add_node_at_the_end(char *name, char *txt, objt_struct_t *strct);
objt_struct_t *set_nodes(objt_struct_t *head, char **env);
char *return_str(char *name, objt_struct_t *head);

//main_name.c
void my_flush(char *str);
int my_fork(char **command, char **envi, char **env);
int launch_program(char *str, char **envi, char **env, objt_struct_t **head);
char *get_name(char *str, int *k);
int mysh(char **env);

char *my_strdup(char const *src);

//my_strcpy.c
char *my_strcpy(char *dest, char const *src);

//start.c
void siginhandler(int sig_num);
void cd_home(objt_struct_t **head);

//my_parse_string.c
int count_args(char *str, char c);
int count_nb_char(char *str, char c, int *i);
char **my_parse_string(char *str, char c);

//my_strcmp.c
int my_count(char const *s);
int my_strcmp(char const *s1, char const *s2);

//end.c
int end_program(char **envi, char *str, int r);
int exit_function(char **command, char **envi, char *str);

//main.c
void print_errors(int status);
void siginhandler(int sig_num);
int main(int ac, char **av, char **env);

//my_strcat.c
int my_count_str(char const *dest);
char *my_strcat(char *dest, char const *src);

//my_putstr.c
void *my_putstr(int fd, char const *str);

//my_str_isupper.c
int my_str_isupper(char const *str);

//my_parse_commands.c
int count_args_co(char *str);
int count_nb_char_co(char *str, char c, int *i);
char **my_parse_commands(char *str, char c);
char **return_good_env(char **env);

//execute.c
int execute_local_commands(char **command, char **envi, char **env);
int execute_executable(char **command, char **env);
int my_executer(char **command, char **envi, char **env);
void my_exec(char **command, char ***envs, node_t *tmp);

//functions.c
int cd(char **command, objt_struct_t **head);
int my_unsetenv(char **command, objt_struct_t **head);
int my_env(objt_struct_t **head);
int my_setenv(char **command, objt_struct_t **head);

//my_put_nbr.c
int my_put_nbr(int nb);

//chained_list.c
void display(objt_struct_t *head);
void remove_node(char *name, objt_struct_t *head);
void modify_node(char *name, objt_struct_t *head, char *txt);
int exist_node(char *name, objt_struct_t *head);

//my_str_isalpha.c
int my_str_isalpha1(char const *str);
int my_str_isalpha2(char const *str);

#endif /* !MY_H_ */