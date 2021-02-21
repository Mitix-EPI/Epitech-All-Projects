/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_exit
*/

#include "asm.h"

void my_exit_next(int error)
{
    if (error == NOT_ENOUGH_ARGUMENTS)
        my_putstr(2, "Error : Not enough parameters on an instruction\n");
    if (error == WRONG_INSTRUCTION)
        my_putstr(2, "Error : Wrong instruction\n");
    if (error == LABEL_NOT_EXIST)
        my_putstr(2, "Error : Called label didn't exists\n");
    if (error == NOT_EXISTING_NAME)
        my_putstr(2, "Error : Name not existing\n");
}

void my_exit(int error)
{
    my_exit_next(error);
    if (error == NOT_NAME_FIRST)
        my_putstr(2, "Error : The name is not first\n");
    if (error == MISSING_QUOTES)
        my_putstr(2, "Error : Missing Quotes\n");
    if (error == NAME_TOO_LONG)
        my_putstr(2, "Error : Size name > 128\n");
    if (error == NOT_COMMENT_SECOND)
        my_putstr(2, "Error : The comment is not second\n");
    if (error == COMMENT_TOO_LONG)
        my_putstr(2, "Error : Size comment > 2048\n");
    if (error == NOT_EXISTING_COMMENT)
        my_putstr(2, "Error : Comment not existing\n");
    if (error == MAX_ARGS_NUMBER)
        my_putstr(2, "Error : Too much arguments\n");
    if (error == INCORRECT_LABEL_NAME)
        my_putstr(2, "Error : Label name contain wrongs characters\n");
    if (error == WRONG_VARIABLE_TYPE)
        my_putstr(2, "Error : Wrong variable parameter on a instruction\n");
    exit(84);
}