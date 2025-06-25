/*
** EPITECH PROJECT, 2024
** rev string
** File description:
** rev_string
*/

#include "../../includes/lib.h"

char *reverse_string(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < len; i++) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
    }
    return str;
}
