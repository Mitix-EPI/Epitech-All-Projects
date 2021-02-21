/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parser
*/

#include "asm.h"

int count_str_until_char(char *str, char c)
{
    int len = 0;

    for (; str && str[len] && str[len] != c; len++);
    return (len);
}

char *get_str_btw_quotes(char *str)
{
    char *res = NULL;
    int i = 0;
    int len = 0;

    for (; str && str[i] && str[i] != 34; i++);
    i++;
    len = count_str_until_char(&str[i], 34);
    res = malloc(sizeof(char) * (len + 1));
    fill_str(res, len, '\0');
    for (int j = 0; str && str[i] && str[i] != 34; i++, j++)
        res[j] = str[i];
    return (res);
}

void get_finally_name(char *str, asm_t *asm_c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == 34)
            count++;
    }
    if (count != 2)
        my_exit(MISSING_QUOTES);
    asm_c->header.prog_name = get_str_btw_quotes(str);
    if (my_strlen(asm_c->header.prog_name) > PROG_NAME_LENGTH)
        my_exit(NAME_TOO_LONG);
}

void get_name_part_two(char *str, int j, asm_t *asm_c)
{
    if (my_strncmp(&str[j], "name", 4) == 0)
        get_finally_name(&str[j + 4], asm_c);
    else
        my_exit(NOT_NAME_FIRST);
}

void get_name(char **arr, int *i, asm_t *asm_c)
{
    for (; arr && arr[*i] != NULL; *i += 1) {
        for (int j = 0; arr[*i][j] && arr[*i][j] != '#'; j++) {
            if (arr[*i][j] == '.') {
                get_name_part_two(arr[*i], j + 1, asm_c);
                return;
            }
        }
    }
}

void get_finally_comment(char *str, asm_t *asm_c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == 34)
            count++;
    }
    if (count != 2)
        my_exit(MISSING_QUOTES);
    asm_c->header.comment = get_str_btw_quotes(str);
    if (my_strlen(asm_c->header.comment) > COMMENT_LENGTH)
        my_exit(COMMENT_TOO_LONG);
}

void get_comment_part_two(char *str, int j, asm_t *asm_c)
{
    if (my_strncmp(&str[j], "comment", 7) == 0) {
        get_finally_comment(&str[j + 7], asm_c);
    } else {
        my_exit(NOT_COMMENT_SECOND);
    }
}

void get_comment(char **arr, int *i, asm_t *asm_c)
{
    for (; arr && arr[*i] != NULL; *i += 1) {
        for (int j = 0; arr[*i][j] && arr[*i][j] != '#'; j++) {
            if (arr[*i][j] == '.') {
                get_comment_part_two(arr[*i], j + 1, asm_c);
                return;
            }
        }
    }
}

void init_asm_c(asm_t *asm_c)
{
    asm_c->header.magic = little_to_big(COREWAR_EXEC_MAGIC);
    asm_c->header.prog_size = 0;
    asm_c->header.prog_name = NULL;
    asm_c->header.comment = NULL;
}

void asm_parser(char **arr, asm_t *asm_c)
{
    int i = 0;

    init_asm_c(asm_c);
    for (; arr && arr[i] != NULL && arr[i][0] == '#'; i++);
    get_name(arr, &i, asm_c);
    if (asm_c->header.prog_name == NULL)
        my_exit(NOT_EXISTING_NAME);
    i++;
    get_comment(arr, &i, asm_c);
    if (asm_c->header.comment == NULL)
        my_exit(NOT_EXISTING_COMMENT);
    i++;
    parse_instructions(asm_c, arr, i);
}
