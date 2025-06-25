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

int prepare_delay(double n)
{
    int delay = 0;
    int nb = n;

    while (nb >= 1 || nb <= -1) {
        n /= 10;
        nb = n;
        delay++;
        }
    while (nb == 0) {
        n *= 10;
        nb = n;
        delay++;
        }
    return delay;
}

void display_digits(int int2, int d, double n)
{
    int next;

    for (int i = 0; i < 7 - d; i++) {
        n *= 10;
        int2 = n;
        int2 %= 10;
        next = n * 10;
        next %= 10;
        if (next >= 5 && i == 6 - d)
            int2++;
        my_printf("%d", int2);
    }
}

int print_decimals_cpy(int int1, double n, int int2, int pow2)
{
    int d = 0;

    int1 = n;
    d = prepare_delay(n);
    if (int1 != 0 && int1 > 10 || int1 < -10 && pow2 != 0)
        n /= my_compute_power_it(10, pow2);
    if (int1 == 0 && pow2 != 0)
        n *= my_compute_power_it(10, - pow2);
    if (n < 0)
        n *= -1;
    display_digits(int2, d, n);
}
