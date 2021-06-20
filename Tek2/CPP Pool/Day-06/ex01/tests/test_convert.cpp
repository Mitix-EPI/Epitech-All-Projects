/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** test_convert
*/

#include "../convert.hpp"
#include <criterion/criterion.h>

Test(convertToCelsius, return_fahrenheit_to_celsius)
{
    float res = convertToCelsius(46.400);
    cr_assert_eq((int)res, 8);
}

Test(convertToFahrenheit, return_celsius_to_fahrenheit)
{
    float res = convertToFahrenheit(10);
    cr_assert_eq((int)res, 50);
}

Test(convert, return_result_celsius)
{
    float res = convert(46.400, 0);
    cr_assert_eq((int)res, 8);
}

Test(convert, return_result_fahrenheit)
{
    float res = convert(10, 1);
    cr_assert_eq((int)res, 50);
}
