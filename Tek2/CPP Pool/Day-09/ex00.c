/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** ex00
*/

#include "ex00.h"

cthulhu_t *new_cthulhu(void)
{
    printf("----\n");
    printf("Building Cthulhu\n");
    cthulhu_t *this = malloc(sizeof(cthulhu_t));
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    return this;
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *koala = malloc(sizeof(koala_t));
    koala->m_parent = *new_cthulhu();
    printf("Building %s\n", name);
    free(koala->m_parent.m_name);
    koala->m_parent.m_name = strdup(name);
    koala->m_is_a_legend = is_a_legend;
    if (is_a_legend == 0) {
        koala->m_parent.m_power = 0;
    }
    return koala;
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    if (this)
        free(this);
    this = new_koala(_name, _is_A_Legend);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    if (this)
        free(this);
    this = new_cthulhu();
}
