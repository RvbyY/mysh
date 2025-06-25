/*
** EPITECH PROJECT, 2024
** exposant
** File description:
** print power of a scientif notation nbr
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"
#include <stdio.h>

int exposant(int pow2)
{
    int ten = 0;

    while (pow2 >= 10 || pow2 <= -10) {
        ten += 1;
        pow2 /= 10;
    }
    if (pow2 > 0) {
        my_putchar('+');
        my_put_nbr(ten);
        my_put_nbr(pow2);
    } else if (pow2 < 0) {
        pow2 *= -1;
        my_putchar('-');
        my_put_nbr(ten);
        my_put_nbr(pow2);
    }
    return pow2;
}
