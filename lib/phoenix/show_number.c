/*
** EPITECH PROJECT, 2024
** show_nbr
** File description:
** show nbr
*/

#include "../../includes/lib.h"

int except(void)
{
    my_putchar('-');
    my_putchar(2 + 48);
    my_putchar(1 + 48);
    my_putchar(4 + 48);
    my_putchar(7 + 48);
    my_putchar(4 + 48);
    my_putchar(8 + 48);
    my_putchar(3 + 48);
    my_putchar(6 + 48);
    my_putchar(4 + 48);
    my_putchar(8 + 48);
    return 0;
}

int show_number(int nb)
{
    int value = 0;

    if (nb == -2147483648) {
        except();
        return 0;
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    } else if (nb == 0)
        my_putchar(48);
    if (nb > 0) {
        value = nb % 10;
        if (nb / 10 != 0)
            show_number(nb / 10);
        my_putchar(value + 48);
    }
    return 0;
}
