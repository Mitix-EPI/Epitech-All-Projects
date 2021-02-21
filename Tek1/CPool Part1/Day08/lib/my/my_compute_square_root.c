/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** return the quare root of the number given as argument
*/

int my_compute_square_root(int nb)
{
    int square = 1;

    if (nb == 0 || nb < 0){
        return (0);
    }
    while (square * square != nb){
        if (square == nb){
            return (0);
        }
        else {
            square++;
        }
    }
    return (square);
}
