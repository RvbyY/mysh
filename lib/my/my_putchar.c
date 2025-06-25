/*
** EPITECH PROJECT, 2024
** putchar
** File description:
** putchar
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../includes/lib.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}
