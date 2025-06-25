/*
** EPITECH PROJECT, 2024
** putfloat G
** File description:
** compare G and F flags
*/

#include "../../includes/lib.h"

double my_putfloat_g_case(double n)
{
    int power = 0;
    int integer = 0;

    power = scientific_style(power, &integer, n);
    if (power < -4 || power >= 12)
        my_printf("%E", n);
    else
        f_flag_cpy(n);
}
