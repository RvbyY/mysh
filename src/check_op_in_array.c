/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** check_op_in_array
*/

#include "../includes/phoenix.h"
#include "../includes/minishell2.h"

int check_op_in_array(char **array)
{
    int n = 84;
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        while (array[i][j] != '\0' && n == 84) {
            n = check_token(array[i][j]);
            j++;
        }
        if (n == 0)
            return 0;
        j = 0;
    }
    return 84;
}
