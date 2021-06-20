/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** convert
*/

#include "convert.hpp"

float convertToFahrenheit(float nb)
{
    return (nb * 9 / 5 + 32);
}

float convertToCelsius(float nb)
{
    return ((nb - 32) * 5 / 9);
}

float convert(float nb, int type)
{
    if (type) {
        return convertToFahrenheit(nb);
    } else {
        return convertToCelsius(nb);
    }
}
