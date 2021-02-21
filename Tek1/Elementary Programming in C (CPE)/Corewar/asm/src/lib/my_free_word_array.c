/*
** EPITECH PROJECT, 2020
** my free word array
** File description:
** function to free a word array variable
*/

#include "asm.h"

void my_free_word_array(char **array)
{
    for (int i = 0; array[i] != NULL; i += 1)
        free(array[i]);
    free(array);
}