/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** test_victim
*/

#include "../Victim.hpp"
#include "criterion/criterion.h"
#include "criterion/redirect.h"

Test(Victim, should_write_in_output)
{
    Victim tmp("Yolo");

    std::cout << tmp; // I'm Yolo and I like otters!\n
    tmp.getPolymorphed(); // Yolo has been turned into a cute little sheep!\n
    cr_assert_eq(0, 0);
}
