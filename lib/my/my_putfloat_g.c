/*
** EPITECH PROJECT, 2024
** put float g
** File description:
** compare between f and g flags
*/

#include "../../includes/lib.h"

double my_putfloat_g(double n)
{
    int power = 0;
    int integer = 0;

    power = scientific_style(power, &integer, n);
    if (power < -4 || power >= 6)
        e_flag_cpy(n);
    else
        f_flag_cpy(n);
}
