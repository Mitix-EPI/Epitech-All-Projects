/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-clement.bolin
** File description:
** test_toy
*/

#include <criterion/criterion.h>
#include "Toy.hpp"

Test(test_toy, test_construct) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    cr_assert_eq(obj.getType(), Toy::ALIEN);
    cr_assert_eq(obj.getName(), "green");
    cr_assert_eq(obj.getAscii(), "hello world");
}

Test(test_toy, test_getName) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    cr_assert_eq(obj.getName(), "green");
}

Test(test_toy, test_getType) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    cr_assert_eq(obj.getType(), Toy::ALIEN);
}

Test(test_toy, test_getAscii) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    cr_assert_eq(obj.getAscii(), "hello world");
}

Test(test_toy, test_setAscii_s) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    cr_assert_eq(obj.setAscii("./tests/file.txt"), true);
}

Test(test_toy, test_setAscii_f) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    cr_assert_eq(obj.setAscii("./tests/file.tx"), false);
}

Test(test_toy, test_setName) {
    Toy obj(Toy::ALIEN, "green", "./tests/file.txt");

    obj.setName("rere");
    cr_assert_eq(obj.getName(), "rere");
}