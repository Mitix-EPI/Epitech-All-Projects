/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** string
*/

#include "string.h"

void call_functions(string_t *this)
{
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->find_c = find_c;
    this->find_s = find_s;
    this->insert_c = insert_c;
    this->insert_s = insert_s;
    this->to_int = to_int;
    this->split_c = split_c;
    this->split_s = split_s;
    this->print = print;
    this->join_c = join_c;
    this->join_s = join_s;
}

void string_init(string_t *this, const char *s)
{
    this->str = (char *)calloc(strlen(s) + 1, sizeof(char));
    strcpy(this->str, s);
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_s = append_s;
    this->append_c = append_c;
    this->at = at;
    this->clear = clear;
    this->size = size;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    call_functions(this);
}

void string_destroy(string_t *this)
{
    free(this->str);
}
