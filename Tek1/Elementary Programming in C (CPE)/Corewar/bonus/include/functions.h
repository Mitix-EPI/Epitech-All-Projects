/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** functions
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
void fill_arr_null(char **arr, int size);
char *my_strcat(char *s1, char *s2);
char *my_revstr(char *str);
int big_to_litlle(int nb);

//main_corewar.c
void main_corewar(char **av, int ac);
void check_all_good_extensions(char **av, int ac);

void write_into_arena(char *arena, int pos, int value);

//fill_champ.c
void fill_champ(champions_t *champ, char *path);
void fill_instructs(champions_t *champ, char *path);
void fill_header(champions_t *champ, char *path);

void loop(core_t *core);
void disp_arena(core_t *core, int cycle);

//st.c
void st_function(champions_t *champ, char *arena, int coding_byte);
void store_content_reg_in_reg(champions_t *champ, char *arena, int reg1, \
int reg2);
void store_content_reg_in_arena(champions_t *champ, char *arena, int reg, \
int index);

//ld.c
void ld_function(champions_t *champ, char *arena, int coding_byte);

//add.c
void add_function(champions_t *champ, char *arena, int coding_byte);
void add_regs(champions_t *champ, char *arena, int arg_1, int arg_2);

//sub.c
void sub_function(champions_t *champ, char *arena, int coding_byte);
void sub_regs(champions_t *champ, char *arena, int arg_1, int arg_2);

//handling_pcs
void handing_pc(champions_t *champ, char *arena);
void handling_pcs(core_t *core);
int give_int(char *arena, int pc, int size);

int exact_extension(char *path, char *ext);

void my_exit(int error);

#endif /* !FUNCTIONS_H_ */
