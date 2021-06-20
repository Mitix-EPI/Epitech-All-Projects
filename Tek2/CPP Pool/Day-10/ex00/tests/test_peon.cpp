/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** test_peon
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../Peon.hpp"

Test(Peon, write_get_polymorphed)
{
    Peon tmp("Bloblo");

    tmp.getPolymorphed(); // Bloblo has been turned into a pink pony!\n
    cr_assert_eq(0, 0);
}
