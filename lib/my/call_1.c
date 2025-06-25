/*
** EPITECH PROJECT, 2024
** call 1
** File description:
** mansur
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../includes/lib.h"

int call_nbr(va_list args, char n, char *str)
{
    my_put_nbr((int)va_arg(args, int));
    return 0;
}

int call_str(va_list args, char n, char *str)
{
    my_putstr((char *)va_arg(args, char *));
    return 0;
}

int call_char(va_list args, char n, char *str)
{
    my_putchar((char)va_arg(args, int));
    return 0;
}

int call_base(va_list args, char n, char *str)
{
    const char *base;

    switch (n) {
    case 'o':
        base = "01234567";
        break;
    case 'x':
        base = "0123456789abcdef";
        break;
    case 'X':
        base = "0123456789ABCDEF";
        break;
    case 'b':
        base = "01";
        break;
    case 'u':
        base = "0123456789";
        break;
    }
    my_put_nbr_base((int)va_arg(args, int), base);
}

int call_n_p(va_list args, char n, char *str)
{
    if (n == 'n')
        len_pointers(str, (int *)va_arg(args, void *));
    else
        my_put_ptr((int)va_arg(args, int), str);
    return 0;
}
