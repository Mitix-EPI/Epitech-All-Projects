/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** main_asm
*/

#include "asm.h"

char **fill_arr(FILE *fp, char **arr, int size)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int i = 0;

    arr = malloc(sizeof(char *) * (size + 1));
    arr[size] = NULL;
    for (; (read = getline(&line, &len, fp) != -1); i++) {
        line[my_strlen(line) - 1] = (line[my_strlen(line) - 1] == '\n') ? '\0' : line[my_strlen(line) - 1];
        arr[i] = my_strdup(line);
    }
    free(line);
    arr[i] = NULL;
    return (arr);
}

int count_line(char *path)
{
    FILE *fp = fopen(path, "r");
    int size = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    for (; (read = getline(&line, &len, fp) != -1); size++);
    return (size);
}

char **read_file(char *path)
{
    FILE *fp;
    char **arr = NULL;
    int size = 0;

    if (exact_extension(path, ".s") == 0)
        exit(84);
    fp = fopen(path, "r");
    if (!fp)
        exit(84);
    size = count_line(path);
    arr = fill_arr(fp, arr, size);
    fclose(fp);
    return (arr);
}

void main_asm(char *path, char **env)
{
    asm_t asm_c;
    char **arr = read_file(path);

    asm_c.good_path = return_good_path(path);
    asm_parser(arr, &asm_c);
    create_cor_file(asm_c.head, asm_c.good_path, &asm_c);
    my_free_word_array(arr);
}