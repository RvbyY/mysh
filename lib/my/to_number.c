/*
** EPITECH PROJECT, 2024
** show_comb
** File description:
** show comb
*/

#include "../../includes/lib.h"

int to_number(char const *str)
{
    int i = 0;
    int minus = 1;
    long int value = 0;
    int temp = str[0];

    while (temp < 48 || temp > 57 && str[i] != '\0') {
        i++;
        temp = str[i];
    }
    if (str[0] == '-')
        minus = -1;
    while (temp >= 48 && temp <= 57) {
        value *= 10;
        value += temp - 48;
        i++;
        temp = str[i];
    }
    if (value > 2147483647 || value < -2147483648)
            return 0;
    return value * minus;
}
