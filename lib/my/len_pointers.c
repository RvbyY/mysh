/*
** EPITECH PROJECT, 2024
** len_pointers
** File description:
** n flag
*/

#include "../../includes/lib.h"
#include <unistd.h>
#include <stdio.h>

int len_pointers(char *str, int *point)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    point = &len;
    return *point;
}
