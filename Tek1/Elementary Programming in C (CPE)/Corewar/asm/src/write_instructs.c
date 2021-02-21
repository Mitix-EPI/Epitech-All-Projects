/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_instructs
*/

#include "asm.h"

static const char *dir[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lldi",
    "lfork",
    NULL
};
static const char *no_cob[] = {"live", "zjmp", "fork", "lfork", NULL};

void write_coding_bytes(int fd, char *type, char c)
{
    for (int i = 0; no_cob[i]; i += 1) {
        if (my_strcmp(type, no_cob[i]) == 0)
            return;
    }
    write(fd, &c, sizeof(c));
}

int little_to_big_short(int var)
{
    int tmp;

    tmp = 0;
    tmp = (var & 0xFF00) / power(2, 8);
    tmp |= ((var & 0x00FF) * power(2, 8));
    return (tmp);
}

int check_label_arg(char *arg, label_t *label, int nb_bytes)
{
    label_t *tmp = label;

    if (arg[0] != ':')
        return (my_atoi(arg));
    arg++;
    for (; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->label_name, arg) == 0)
            return (tmp->byte_position - nb_bytes);
    my_exit(LABEL_NOT_EXIST);
}

char *check_type_arg(char **arg)
{
    char *str = malloc(sizeof(int));
    int len = 0;

    str[0] = '\0';
    for (int i = 0; arg[i]; i++) {
        if (arg[i][0] == 'r')
            str = my_strcat(str, "01");
        else if (arg[i][0] == '%')
            str = my_strcat(str, "10");
        else
            str = my_strcat(str, "11");
    }
    if ((len = my_strlen(str)) != 8) {
        for (; len != 8; len++)
            str = my_strcat(str, "0");
    }
    return (str);
}

void writer_dir(int fd, char *type, int value)
{
    for (int i = 0; dir[i]; i += 1)
        if (my_strcmp(dir[i], type) == 0) {
            value = little_to_big_short(value);
            write(fd, &value, IND_SIZE);
            return;
        }
    value = little_to_big(value);
    write(fd, &value, DIR_SIZE);
}

void write_args(int val[2], char *value, label_t *label, char *inst)
{
    char *tmp = value;

    if (tmp[0] == 'r') {
        tmp++;
        int test = my_atoi(tmp);
        write(val[0], &test, 1);
    }
    else if (tmp[0] == '%') {
        tmp++;
        int test = check_label_arg(tmp, label, val[1]);
        writer_dir(val[0], inst, test);
    } else {
        int test = little_to_big_short(my_atoi(tmp));
        write(val[0], &test, IND_SIZE);
    }
}

void write_function(int fd, char *type)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i += 1)
        if (my_strcmp(type, op_tab[i].mnemonique) == 0) {
            write(fd, &op_tab[i].code, sizeof(op_tab[i].code));
            return;
        }
    my_exit(WRONG_INSTRUCTION);
}

long long char_to_long_long(char *str)
{
    long long nb = 0;

    for (int i = 0; str[i]; i += 1) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return (nb);
}

char *binary_to_hex(char *str)
{
    // printf("\nstr : %s\n", str);
    int hexConstant[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000,
    1001, 1010, 1011, 1100, 1101, 1110, 1111};
    long long binary = char_to_long_long(str);
    char *hex = malloc(sizeof(char) * 20);
    int index = 0;

    for (long long tempBinary = binary; tempBinary != 0; tempBinary /= 10000)
        for(int i = 0; i < 16; i++)
            if(hexConstant[i] == tempBinary % 10000) {
                (i < 10) ? (hex[index] = (char)(i + 48)) :
                (hex[index] = (char)(i - 10 + 65));
                index++;
                break;
            }
    hex[index] = '\0';
    hex = my_revstr(hex);
    // printf("Hexadecimal number = %s\n", hex);
    return (hex);
}

int getnum(char ch)
{
    int num = 0;

    if(ch >= '0' && ch <= '9')
        num = ch - 0x30;
    else
        switch(ch)
        {
            case 'A' : case 'a' : num = 10; break;
            case 'B' : case 'b' : num = 11; break;
            case 'C' : case 'c' : num = 12; break;
            case 'D' : case 'd' : num = 13; break;
            case 'E' : case 'e' : num = 14; break;
            case 'F' : case 'f' : num = 15; break;
            default : num = 0;
        }
    return (num);
}

void write_instruc(int fd, line_t line, label_t *label)
{
    // for (int i = 0; line.arg && line.arg[i] != NULL; i++);
    //     // printf("%s\n", line.arg[i]);
    char *args = check_type_arg(line.arg);
    // printf("args : %s\n", args);
    char *hex = binary_to_hex(args);
    char c = getnum(hex[0]) * 16 + getnum(hex[1]);

    write_function(fd, line.type);
    write_coding_bytes(fd, line.type, c);
    for (int i = 0; line.arg[i]; i += 1) {
        write_args((int [2]){fd, line.nb_byte}, line.arg[i], label, line.type);
    }
}
