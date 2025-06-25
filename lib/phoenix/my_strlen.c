/*
** EPITECH PROJECT, 2024
** putchar
** File description:
** print char
*/

#include "../../includes/lib.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (len; str[len] != '\0'; len++);
    return len;
}
