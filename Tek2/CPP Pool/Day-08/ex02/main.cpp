/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** main
*/

#include"Droid.hpp"
#include"DroidMemory.hpp"

static void testMemory()
{
    DroidMemory mem1;
    mem1 += 42;
    std ::cout << mem1 << std ::endl;
    DroidMemory mem2;
    mem2 << mem1;
    mem2 >> mem1;
    mem2 << mem1;
    std ::cout << mem2 << std ::endl;
    std ::cout << mem1 << std ::endl;
    DroidMemory mem3 = mem1;
    DroidMemory mem4;
    mem4 = mem1 + mem3;
}
static void testDroids()
{
    Droid d("rudolf");
    Droid d2("gaston");
    size_t DuraSell = 40;
    d << DuraSell;
    d.setStatus(new std ::string("having some reset"));
    d2.setStatus(new std ::string("having some reset"));
    if (d2 != d && !(d == d2))
        std ::cout <<"a droid is a droid , all its matter is what it 's doing"<< std ::endl;
    d(new std ::string("take a coffee"), 20);
    std ::cout << d << std ::endl;
    while (d(new std ::string("Patrol around"), 20))
    {
        if (!d(new std ::string("Shoot some ennemies"), 50))
            d(new std ::string("Run Away"), 20);
        std ::cout << d << std ::endl;
    }
    std ::cout << d << std ::endl;
}
int main()
{
    testMemory();
    testDroids();
    return 0;
}