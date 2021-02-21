/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void man(void)
{
    write(1, "\x1B[34mUSAGE :\x1B[0m\n\t./my_defender\n\n\
\x1B[33mTOOLS :\x1B[0m\
    \n\tpress h to back home\n\tpress ECHAP to quit the game\
    \n\tin options, press x to level down the song\
    \n\tin options, press c to level down the song\n\n\
\x1B[31mGAMEPLAY :\x1B[0m\n\
    \tYou can click on each turret. The more it costs, the (shot) faster \
it is !\n\tPut it on the battlefield and protect our base!\n\
\tEach ennemy killed bring back 10$\n\tYou can also sell the turrets \
-> click right on a turret (you need good precision)\n\n\
\x1B[32mSTORY LINE:\x1B[0m\
    \n\t   Hey Conqueror !\n\tOur base is attacked !\
    \n\t  WE NEED YOUR HELP!\n", 567);
}