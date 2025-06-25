/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** prep_array
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

int operator_nb(char *str)
{
    int op_nb = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (check_token(str[i]) == 0)
            op_nb++;
    return op_nb;
}

char *cut_operator(char *str)
{
    int len = my_strlen(str);
    int op_nb = operator_nb(str);
    char *copy = malloc(sizeof(char) * (len + (op_nb * 2) + 1));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_token(str[i]) == 0) {
            copy[j] = ' ';
            j++;
            copy[j] = str[i];
            j++;
            copy[j] = ' ';
            j++;
            continue;
        }
        copy[j] = str[i];
        j++;
    }
    copy[len + (op_nb * 2)] = '\0';
    return copy;
}

char *conc_redirect(char *str)
{
    int red_i = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == TOKEN_REDIRECT_L ||
            str[i] == TOKEN_REDIRECT_R) && red_i == 1) {
            str[i - 2] = str[i];
            str[i] = ' ';
            continue;
        }
        if (str[i] == TOKEN_REDIRECT_L ||
            str[i] == TOKEN_REDIRECT_R) {
            red_i = 1;
            continue;
        }
        if (str[i] != ' ') {
            red_i = 0;
            continue;
        }
    }
    return str;
}

char **prep_array(char **argv)
{
    char **copy;
    int i = 0;
    int j = 0;
    char *str_array;
    char *cut_str;

    if (!argv)
        return NULL;
    for (j; argv[j] != NULL; j++);
    str_array = array_to_string(argv, j, i);
    cut_str = cut_operator(str_array);
    cut_str = conc_redirect(cut_str);
    copy = split_string(cut_str, " ");
    free_char_array(argv);
    free(cut_str);
    free(str_array);
    return copy;
}
