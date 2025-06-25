/*
** EPITECH PROJECT, 2024
** call 2
** File description:
** mansur
*/

#include <stdarg.h>
#include "../../includes/lib.h"

int call_f(va_list args, char n)
{
    my_putfloat((double)va_arg(args, double));
    return 0;
}

int call_case(va_list args, char n)
{
    my_putfloat_case((double)va_arg(args, double));
    return 0;
}

int call_e(va_list args, char n)
{
    my_putfloat_e((double)va_arg(args, double));
    return 0;
}

int call_e_case(va_list args, char n)
{
    my_putfloat_e_case((double)va_arg(args, double));
    return 0;
}

int call_g(va_list args, char n)
{
    if (n == 'g')
        my_putfloat_g((double)va_arg(args, double));
    else if (n == 'G')
        my_putfloat_g_case((double)va_arg(args, double));
    return 0;
}
