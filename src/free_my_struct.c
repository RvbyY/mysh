/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** free_my_struct
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

void free_struct_array(element_t **array)
{
    if (!array)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]->next_arg);
        free(array[i]->pre_arg);
        free(array[i]->token.token);
    }
    free(array);
}

void free_struct_list(list_t *my_list)
{
    if (!my_list)
        return;
    while (my_list) {
        free(my_list->next_arg);
        my_list = my_list->next;
    }
    free(my_list);
}
