/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** split
*/

#include "string.h"
#include <string.h>

string_t **split_s(const string_t *this, char separator)
{
    int len = 1;
    char *word = NULL;
    char *tmp = strdup(this->str);
    char *free_tmp = tmp;
    char sep[1];

    sep[0] = separator;
    for (size_t i = 0; i < strlen(tmp); i++)
        if (tmp[i] == separator)
            len++;
    string_t **res = (string_t **)calloc(len + 1, sizeof(string_t *));
    for (int i = 0; i < len; i++) {
        word = strsep(&tmp, sep);
        res[i] = malloc(sizeof(string_t));
        string_init(res[i], word);
    }
    free(free_tmp);
    return res;
}

char **split_c(const string_t *this, char separator)
{
    int len = 1;
    char *word = NULL;
    char *tmp = strdup(this->str);
    char *free_tmp = tmp;
    char sep[1];

    sep[0] = separator;
    for (size_t i = 0; i < strlen(tmp); i++)
        if (tmp[i] == separator)
            len++;
    char **res = (char **)calloc(len + 1, sizeof(char *));
    for (int i = 0; i < len; i++) {
        word = strsep(&tmp, sep);
        res[i] = (char *)calloc(strlen(word) + 1, sizeof(char));
        strcpy(res[i], word);
    }
    free(free_tmp);
    return res;
}
