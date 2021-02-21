/*
** EPITECH PROJECT, 2020
** functions.h
** File description:
** header
*/

void display_movement(ants_t *, int *, node_t **, int *);
void algorithm(node_t **, paths_t *);
int find_best_id(node_t *, ants_t *, int *);
void init_nodes_distances(node_t **, paths_t *);
void push_link(node_t *, node_t *);
int count_link(link_t *);
node_t *new_node(const char *);
node_t *get_node(char *, node_t **);
node_t *get_node_from_id(int, node_t **);
void free_node(node_t *);
void free_nodes(node_t **);
int check_if_possible(paths_t *, node_t *);
void link_all_nodes(paths_t *, node_t **);
node_t **create_all_nodes(paths_t *);
char *get_second_id(char *);
int main_lemin(void);
int get_nb_digit(int);
int my_isalnum(char);
int my_atoi(const char *);
int count_numbers(char *, int);
int what_line(char *);
void my_itoa(char *, int);
void my_putnbr(int);
int my_putstr(int, char *);
char *my_realloc(char *, int);
int check_str(char);
char *my_str(char *);
int jump_index(int, char *, char);
int count_words_array(char *, char);
int my_strlen_array(char *, int, char);
char **my_str_to_word_array(char, char *);
int my_strncmp(char *, char *, int, int);
int my_strcmp(char *, char *);
char *my_strcpy(const char *);
int my_strlen(const char *);
int count_spaces(char *);
int check_not_equal(char **);
int get_comparison_start_end(char **, paths_t *, int, int);
int check_link_correspond(paths_t *, char **);
int check_the_link(paths_t *, char *);
int check_ant_nb(char *, paths_t *);
int check_start_end_str(char *, paths_t *);
void cutstr(char *);
void display_debug(paths_t *);
void free_path(paths_t *);
void init_path(paths_t *);
int handling_path(paths_t *);
void set_start_end_str(paths_t *, int);
int set_node_or_link(char *, paths_t *, int);
void parse_paths(paths_t *);
paths_t *read_file(void);
char **copy_arrays(char **, char **);
int count_arr(char **);
char **realloc_array(char **, char *);
int check_my_node(char *);
void check_name_node(paths_t *);