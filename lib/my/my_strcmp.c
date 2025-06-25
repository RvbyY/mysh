/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** compare two strings to return the difference.
*/

#include "../../includes/lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return 84;
    while (*s1 && (*s1 == *s2)) {
        if (*s1 != *s2) {
            return (unsigned char)(*s1) - (unsigned char)(*s2);
        }
        s1++;
        s2++;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}
