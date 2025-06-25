/*
** EPITECH PROJECT, 2024
** my_put_ptr
** File description:
** mansur
*/

#include "../../includes/lib.h"

int my_put_ptr(int ptr, char *str)
{
    my_putstr("0x");
    my_put_nbr_base(ptr, "0123456789abcdef");
}
