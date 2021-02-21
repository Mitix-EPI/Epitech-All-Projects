/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** sapin
*/

#include <unistd.h>

void print_stars_line(int nb_star)
{
    int count = 0;
    int star = '*';
    while (count < nb_star){
        write(1, &star, 1);
        count++;
    }
}

int print_spaces_line(int nb_space)
{
    int count = 0;
    int space = ' ';

    while (count <= nb_space){
        write(1, &space, 1);
        count++;
    }
    nb_space--;
    return (nb_space);
}

int nb_star_end_part(int part)
{
    int start_part = 1;
    int end_star = 7;
    int add = 6;

    while (start_part < part){
        start_part++;
        if (start_part % 2 == 0){
            end_star = end_star + add;
        }
        else {
            add = add + 2;
            end_star = end_star + add;
        }
    }
    return (end_star);
}

void tronc(int n, int nb_stars_max)
{
    int count = 0;
    int space = 0;
    int spaces_charac = ' ';
    int nb = n;
    int tronc = '|';
    int enter = '\n';
    int count1 = 0;

    space = (nb_stars_max / 2) - (n / 2);
    if (n % 2 == 0){
        nb++;
    }
    while (count1 < n){
        count = 0;
        while (count < space){
            write(1, &spaces_charac, 1);
            count++;
        }
        count = 0;
        while (count < nb){
            write(1, &tronc, 1);
            count++;
        }
        count1 = count1 + 1;
        write(1, &enter, 1);
    }
}

void tree(int n)
{
    int nb_space;
    int part = 0;
    int nb_stars = 1;
    int nb_stars_max = 7;
    int enter = '\n';
    int add = 4;

    nb_space = (nb_star_end_part(n) / 2) - 1;
    while (part < n){
        part++;
        nb_stars_max = nb_star_end_part(part);
        while (nb_stars <= nb_stars_max){
            print_spaces_line(nb_space);
            print_stars_line(nb_stars);
            write(1, &enter, 1);
            nb_stars = nb_stars + 2;
            nb_space = nb_space - 1;
        }
        if (nb_stars >= nb_stars_max){
            nb_stars = nb_stars - add;
            if (add % 2 == 0){
                nb_space = nb_space + (add / 2);
            }
            else {
                nb_space = nb_space + (add / 2) + 1;
            }
            if (part % 2 == 0){
                add = add + 2;
            }
        }
    }
    tronc(n, nb_stars_max);
}


void main(void)
{
    tree(3);
}