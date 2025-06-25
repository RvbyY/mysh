/*
** EPITECH PROJECT, 2024
** scientific style
** File description:
** put a nbr in scritifc notation
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"
#include <stdio.h>

int scientific_style(int powr, int *int1, double n)
{
    *int1 = n;
    if (*int1 >= 10 || *int1 <= -10) {
        while (*int1 >= 10 || *int1 <= -10) {
            n /= 10;
            powr++;
            *int1 = n;
        }
    } else {
        while (*int1 == 0) {
            n *= 10;
            powr--;
            *int1 = n;
        }
    }
    return powr;
}
