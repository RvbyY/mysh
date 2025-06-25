/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** my_strncmp
*/

#include "../../includes/lib.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int ascii_val_s1 = 0;
    int ascii_val_s2 = 0;

    if (!s1 || !s2)
        return 84;
    for (int i = 0; i < n; i++) {
        if (!s1[i] || !s2[i])
            return 84;
        ascii_val_s1 += s1[i];
        ascii_val_s2 += s2[i];
    }
    return ascii_val_s1 - ascii_val_s2;
}
