/*
** EPITECH PROJECT, 2020
** functions
** File description:
** prototypes of functions for asm
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// lib
int my_atoi(const char *str);
void my_free_word_array(char **array);
void my_cutstr(char *str);
void my_putstr(const int, char *);
int read_yolotron(char *);
void fill_str(char *str, int len, char c);
void my_cutstr(char *);
int my_strlen(char *);
void analyse_command(char *);
int my_strcmp(char const *, char const *);
int my_isnum(char const *);
int my_atoi(const char *);
void my_put_nbr(int);
int add_values(char *, char *);
int remove_values(char *, char *);
int display(char *);
void my_putchar(const int, char);
long int power(int nb, int nb_power);
int little_to_big(int nb);
char *my_strdup(char *str);
int my_strncmp(char *s1, char *s2, int n);
int check_empty_line(char *str);
void add_element(node_t **list, line_t line);
void remove_element(node_t **list, int position);
void insert_element(node_t **list, int position, line_t line);
void destroy_list(node_t **list);
int get_size_list(node_t *list);
void fill_arr_null(char **arr, int size);
char *my_strcat(char *s1, char *s2);
char *my_revstr(char *str);
int check_label(char *ln);
void add_element_label(label_t **list, int pos, char *label);
int is_label_without_instruction(char *ln);
char **word_array(char *str, char autho[], char *inter_num[3]);
void main_asm(char *path, char **env);
void create_cor_file(node_t *head, char *path, asm_t *asm_c);

void my_exit(int error);

void parse_instructions(asm_t *asm_c, char **arr, int i);

int exact_extension(char *path, char *ext);

char *return_good_path(char *path);

int line_parser(char *ln);

int check_variable(char *ln);

void create_label(char *line, int *i, label_t **label, asm_t *asm_file);

//parser.c
void asm_parser(char **, asm_t *);

//write_header
int write_header(int fd, char *name, char *comment, int size_prog);
void write_magic_number(int fd);
void write_name(int fd, char *name, int size_prog);
void write_comment(int fd, char *comment);

//write_instructs
void write_instruc(int fd, line_t line, label_t *label);
void write_function(int fd, char *type);
void write_args(int val[2], char *value, label_t *label, char *inst);
char *check_type_arg(char **arg);
int getnum(char ch);
char *binary_to_hex(char *str);

//cal_pos
void calc_size_header_suite(header_t *beg, int *size);
int calc_size_header(header_t *header);
int calc_size_arg(char *type);
int calc_args(char *value, char *type);
void give_bytepos(asm_t *asm_file, line_t *new_line);
int calc_coding_byte(char c, char *arg);

#endif
