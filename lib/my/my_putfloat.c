/*
** EPITECH PROJECT, 2024
** put float
** File description:
** put float
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"
#include <stdio.h>

double my_putfloat(double n)
{
    int int1 = (int)n;
    int int2 = 0;
    int pwr = 0;

    my_put_nbr(int1);
    my_putchar('.');
    print_decimals(int1, n, int2, pwr);
    return n;
}
