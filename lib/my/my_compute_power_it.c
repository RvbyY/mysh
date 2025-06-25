/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** power of a nb
*/

#include "../../includes/lib.h"

int my_compute_power_it(int nb, int p)
{
    int resultat = nb;
    int i = 1;
    int p1 = p;

    if (p1 == 0) {
        return (1);
    } else if (p1 < 0) {
        return (0);
    }
    for (i; i < p1; i++) {
        resultat *= nb;
    }
    return (resultat);
}
