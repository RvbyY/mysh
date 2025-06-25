/*
** EPITECH PROJECT, 2024
** recursive_power
** File description:
** recuv power
*/

#include "../../includes/lib.h"

int find_square(int x)
{
    int i = 1;
    int result = 1;

    if (x == 0 || x == 1)
        return x;
    for (i; result <= x; i++)
        result = i * i;
    return i - 1;
}

int is_prime_number(int nb)
{
    int square_root = find_square(nb);
    int result = 1;

    if (nb == 0 || nb == 1)
        return 0;
    else if (nb < 0)
        return 84;
    if (nb == 2)
        return 1;
    for (int i = 2; i < square_root; i++) {
        if (nb % i == 0)
            return 0;
    }
    return result;
}
