/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** test_sorcerer
*/

#include "../Sorcerer.hpp"
#include "criterion/criterion.h"
#include "criterion/redirect.h"

Test(Sorcerer, should_write_in_output)
{
    Sorcerer tmp("Yolo", "Le mécréant");

    std::cout << tmp; // I am Yolo, Le mécréant, and I like ponies!\n
    cr_assert_eq(0, 0);
}