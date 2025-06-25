/*
** EPITECH PROJECT, 2024
** put nbr
** File description:
** put nbr
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"

int display_except(void)
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
}

int my_put_nbr(int n)
{
    int digit = 0;

    if (n == -2147483648) {
        display_except();
        return 84;
    }
    if (n == 0) {
        my_putchar(48);
    } else if (n < 0) {
        my_putchar('-');
        n = n * -1;
    }
    if (n > 0) {
        digit = n % 10;
        if (n / 10 != 0) {
            my_put_nbr(n / 10);
        }
        my_putchar(digit + 48);
    }
}
