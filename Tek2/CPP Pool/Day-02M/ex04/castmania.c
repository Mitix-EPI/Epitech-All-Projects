/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02M-alexandre.juan
** File description:
** castmania
*/

#include "castmania.h"
#include <stdio.h>

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *output = data;
    if (instruction_type == ADD_OPERATION) {
        addition_t *addition = output->operation;
        exec_add(addition);
        if (output->output_type == VERBOSE)
            printf("%d\n", addition->add_op.res);
    }
    if (instruction_type == DIV_OPERATION) {
        division_t *div = output->operation;
        exec_div(div);
        if (output->output_type == VERBOSE) {
            if (div->div_type == INTEGER) {
                integer_op_t *int_op = div->div_op;
                printf("%d\n", int_op->res);
            } else if (div->div_type == DECIMALE) {
                decimale_op_t *dec_op = div->div_op;
                printf("%f\n", dec_op->res);
            }
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT) {
        int *num = data;
        printf("%d\n", *num);
    } else if (instruction_type == PRINT_FLOAT) {
        float *num = data;
        printf("%f\n", *num);
    } else {
        exec_operation(instruction_type, data);
    }
}
