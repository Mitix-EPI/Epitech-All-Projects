/*
** EPITECH PROJECT, 2021
** RUSH3
** File description:
** main
*/
#include "Cpu.hpp"
#include <unistd.h>

int main(void)
{
    Cpu cpu;

    // unsigned int microsecond = 1000000;
    while (1) {
        cpu.update();
        cpu.print();
        sleep(1);
    }
    return (0);
}