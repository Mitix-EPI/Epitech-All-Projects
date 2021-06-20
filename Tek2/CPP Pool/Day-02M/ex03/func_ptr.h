/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02M-alexandre.juan
** File description:
** func_ptr
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func_ptr_enum.h"

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

typedef void (*operate)(const char *);

typedef struct functions_s {
    operate act[4];
} functions_t;

#endif /* !FUNC_PTR_H_ */
