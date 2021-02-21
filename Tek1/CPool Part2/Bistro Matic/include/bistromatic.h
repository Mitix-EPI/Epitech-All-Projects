/*
** EPITECH PROJECT, 2019
** bistromatic.h
** File description:
** prototypes + define
*/

#ifndef BISTROMATIC_H_
#define BISTROMATIC_H_

#define OP_OPEN_PARENT_IDX      0
#define OP_CLOSE_PARENT_IDX     1
#define OP_PLUS_IDX             2
#define OP_SUB_IDX              3
#define OP_NEG_IDX              3
#define OP_MULT_IDX             4
#define OP_DIV_IDX              5
#define OP_MOD_IDX              6

#define EXIT_USAGE      84
#define EXIT_BASE       84
#define EXIT_SIZE_NEG   84
#define EXIT_MALLOC     84
#define EXIT_READ       84
#define EXIT_OPS        84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_atoi(char *str);
int my_putstr_error(char const *str);

int help(void);
int check_para(char *expr, char const *ops);
static void check_base(char const *b);
static void check_ops(char const *ops);
static char *get_expr(unsigned int size);
char *eval_expr(char const *base, char const *ops, char *expr, int size);
char *translate(char const *base, char const *ops, char const *expr, char *str);
int check_h(char *str);
void check_last_charac(char *expr);
int return_ops(int j);
char *eval_expr1(char const *str);
char *my_parse_factor(void);
char *my_parse_product(void);
char *my_parse_sum(void);
void opeator_handling(char *str);
void check_existing_charac(char *expr, char *base, char *ops);
int check_opr(char c);
char *mult(char *str1, char *str2);
void check_expr_empty(char *expr);
int check_para(char *expr, char const *ops);
char *re_translate(char const *base, char *str, char *res, char const *ops);
void error_too_many_arg(void);
void error_less_arg(void);
char *add_all(char *str1, char *str2, char *res);
char *substract_all(char *str1, char *str2, char *res);
int check_letter(char *str);
void error_have_letter(void);
char *infin_add(char *str1, char *str2);
char *my_itoa(int i);
int get_int_len (int value);
int my_atoi(char *str);
char *main_infin_add(char *av1, char *av2);
char *infin_sub(char *str1, char *str2);

#endif /* !BISTROMATIC_H_ */
