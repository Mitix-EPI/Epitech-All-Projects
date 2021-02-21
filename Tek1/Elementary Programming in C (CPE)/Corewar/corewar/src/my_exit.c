/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_exit
*/

#include "corewar.h"

void my_exit(int error)
{
    if (error == NOT_GOOD_EXTENSION)
        my_putstr(2, "Error : Not good extension for champion\n");
    if (error == NOT_ENOUGHT_CHAMPS)
        my_putstr(2, "Error : Not enought champion(s)\n");
    if (error == CANT_OPEN_FILE)
        my_putstr(2, "Error : Can't open one arg\n");
    if (error == CANT_READ_INSTRUCT)
        my_putstr(2, "Error : Can't read instructions\n");
    if (error == CANT_READ_HEADER)
        my_putstr(2, "Error : Can't read header\n");
    if (error == ID_ALREADY_TAKEN)
        my_putstr(2, "Error : Id already Taken\n");
    exit(84);
}