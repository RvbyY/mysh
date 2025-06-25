/*
** EPITECH PROJECT, 2024
** put %
** File description:
** put %
*/

#include <stdarg.h>
#include <unistd.h>
#include "../../includes/lib.h"

int my_putpercentage(float percentage)
{
    int integer1 = (int)percentage;
    int temp = percentage * 100;
    int integer2 = temp % (integer1 * 100);

    my_put_nbr(integer1);
    my_putchar('.');
    my_put_nbr(integer2);
    my_putchar('%');
}
