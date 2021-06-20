/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef union __attribute__((packed)) foo_s
{
    struct {
        int16_t foo;
        union{
            int16_t bar;
            int16_t foo;
        }bar;
    }foo;
    int32_t bar;
} foo_t;

#endif /* !EX05_H_ */
