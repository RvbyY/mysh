/*
** EPITECH PROJECT, 2024
** put float E
** File description:
** put float
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"
#include <stdio.h>

int my_putfloat_e_case(double n)
{
    int powr = 0;
    int int1 = 0;
    int int2 = 0;
    int pow2 = 0;

    pow2 = scientific_style(powr, &int1, n);
    my_put_nbr(int1);
    my_putchar('.');
    print_decimals(int1, n, int2, pow2);
    my_putchar('E');
    exposant(pow2);
    return pow2;
}
