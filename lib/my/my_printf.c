/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** mansur
*/

#include <stdarg.h>
#include "../../includes/lib.h"
#include <unistd.h>

int call_function_1(char n, va_list args, char *str)
{
    char array[12] = {'d', 'i', 's', 'c', '%', 'o',
                    'u', 'x', 'X', 'b', 'n', 'p'};
    int (*function_array[12])(va_list, char, char *) = {call_nbr, call_nbr,
                                call_str, call_char, call_char, call_base,
                                call_base, call_base, call_base,
                                call_base, call_n_p, call_n_p};

    if (n == 'f' || n == 'F' || n == 'e' || n == 'E' || n == 'g' || n == 'G') {
            call_function_2(n, args);
            return 0;
        }
    for (int i = 0; array[i] != '\0'; i++) {
        if (n == array[i]) {
            (function_array[i](args, n, str));
        }
    }
}

int call_function_2(char n, va_list args)
{
    char array[6] = {'f', 'F', 'e', 'E', 'g', 'G'};
    int i = 0;
    int (*function_array[6])(va_list, char) = {call_f, call_case,
                                    call_e, call_e_case, call_g,
                                    call_g};

    for (i; array[i] != '\0'; i++) {
        if (n == array[i])
            function_array[i](args, n);
    }
}

int my_printf(const char *format, ...)
{
    va_list args;
    char *str;
    int output = 0;
    int len = my_strlen(format);

    str = malloc(sizeof(char) * (len));
    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            output = call_function_1(format[i], args, str);
        } else {
            my_putchar(format[i]);
            str[i] = format[i];
        }
        if (output == -1)
            return -1;
    }
        va_end(args);
}
