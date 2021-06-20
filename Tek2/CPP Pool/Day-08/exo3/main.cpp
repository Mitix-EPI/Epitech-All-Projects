/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** main
*/

#include "Droid.hpp"
#include "Carrier.hpp"

int main()
{
    Carrier c("HellExpress");
    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");
    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std ::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std ::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std ::endl;
    c(4, 2);
    std::cout << c << std ::endl;
    c(-15, 4);
    std::cout << c << std ::endl;
    c[3] = 0;
    c[4] = 0;
    (~c)(-15, 4);
    std ::cout << c << std ::endl;
    return 0;
}