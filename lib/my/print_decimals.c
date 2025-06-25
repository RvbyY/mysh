/*
** EPITECH PROJECT, 2024
** print decimals
** File description:
** print decimals
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"
#include <stdio.h>

int print_decimals(int int1, double n, int int2, int pow2)
{
    int next;

    int1 = n;
    if (int1 >= 10 && pow2 != 0 || int1 <= -10 && pow2 != 0)
        n /= my_compute_power_it(10, pow2);
    if (int1 == 0 && pow2 != 0)
        n *= my_compute_power_it(10, - pow2);
    if (n < 0)
        n *= -1;
    for (int i = 0; i < 6; i++) {
        n *= 10;
        int2 = n;
        int2 %= 10;
        next = n * 10;
        next %= 10;
        if (next >= 5 && i == 5)
            int2++;
        my_printf("%d", int2);
    }
}
