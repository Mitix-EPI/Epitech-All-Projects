/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** main
*/

#include "Droid.hpp"

int main()
{
    DroidMemory mem1;
    mem1 += 42;
    DroidMemory mem2 = mem1;
    std ::cout << mem1 << std ::endl;
    DroidMemory mem3;
    mem3 << mem1;
    mem3 >> mem1;
    mem3 << mem1;
    std ::cout << mem3 << std ::endl;
    std ::cout << mem1 << std ::endl;
}