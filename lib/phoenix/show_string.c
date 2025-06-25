/*
** EPITECH PROJECT, 2024
** show_string
** File description:
** show string
*/

#include "../../includes/lib.h"

int show_string(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
