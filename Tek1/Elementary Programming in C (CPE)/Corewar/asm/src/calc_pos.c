/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** calc_pos
*/

#include "asm.h"

const static char *except[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lldi",
    "lfork",
    NULL
};
static const char *array[] = {"live", "zjmp", "fork", "lfork", NULL};

int calc_coding_byte(char c, char *arg)
{
     for (int i = 0; array[i]; i += 1) {
        if (my_strcmp(arg, array[i]) == 0)
            return (0);
    }
    return (sizeof(c));
}

void calc_size_header_suite(header_t *beg, int *size)
{
    char *tmp = my_strdup(beg->comment);
    int len = my_strlen(tmp);
    int tmp_n = 0;

    *size += len;
    len = PROG_NAME_LENGTH - len;
    for (int i = 0; i < len; i += 1)
        *size += 1;
    *size += sizeof(tmp_n);
    free(tmp);
}

int calc_size_header(header_t *header)
{
    int magic = little_to_big(COREWAR_EXEC_MAGIC);
    int size = 0;
    char *tmp = my_strdup(header->prog_name);
    int len = my_strlen(tmp);
    int tmp_n = 0;

    size  += sizeof(magic);
    size += len;
    len = PROG_NAME_LENGTH - len;
    for (int i = 0; i < len; i += 1)
        size += 1;
    size += sizeof(tmp_n);
    tmp_n = header->prog_size;
    size += sizeof(tmp_n);
    calc_size_header_suite(header, &size);
    free (tmp);
    return (size);
}

int calc_size_arg(char *type)
{
    int size = 0;

    for (int i = 0; op_tab[i].mnemonique != 0; i += 1)
        if (my_strcmp(type, op_tab[i].mnemonique) == 0) {
            size = sizeof(op_tab[i].code);
            return (size);
        }
    write(2, "No such functions\n", 19);
    exit (84);
}

int calc_dir_pos(char *type)
{
    for (int i = 0; except[i]; i += 1)
        if (my_strcmp(except[i], type) == 0)
            return (IND_SIZE);
    return (DIR_SIZE);
}

int calc_args(char *value, char *type)
{
    char *tmp = value;
    int size = 0;

    if (value[0] == 'r')
        size = 1;
    else if (value[0] == '%')
        size = calc_dir_pos(type);
    else
        size = 2;
    return (size);
}

void give_bytepos(asm_t *asm_file, line_t *new_line)
{
    static int pos = 0;
    static int to_do = 0;
    char *args = check_type_arg(new_line->arg);
    char *hex = binary_to_hex(args);
    char c = getnum(hex[0]) * 16 + getnum(hex[1]);

    if (to_do == 0) {
        pos = calc_size_header(&asm_file->header);
        to_do++;
    }
    printf("pos = %d\n", pos);
    new_line->nb_byte = pos;
    pos += calc_size_arg(new_line->type);
    pos += calc_coding_byte(c, new_line->type);
    for (int i = 0; new_line->arg[i]; i += 1)
        pos += calc_args(new_line->arg[i], new_line->type);
}