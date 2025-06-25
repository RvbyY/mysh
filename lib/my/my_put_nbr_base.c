/*
** EPITECH PROJECT, 2024
** my_put
** File description:
** mansur
*/

#include <unistd.h>
#include "../../includes/lib.h"

int my_put_nbr_base(unsigned int nbr, char const *base)
{
    int len_base = my_strlen(base);

    if (nbr)
        my_put_nbr_base(nbr / len_base, base);
    else
        return (0);
    my_putchar(base[nbr % len_base]);
    return (0);
}
