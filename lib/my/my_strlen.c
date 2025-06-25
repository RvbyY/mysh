/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** len of a string
*/

#include <stdio.h>
#include "../../includes/lib.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (i; str[i] != '\0'; ++i);
    return (i);
}
