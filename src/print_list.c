/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** print_list
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

void print_my_list(list_t *my_list)
{
    while (my_list) {
        my_printf("type: %d pre args: %s next args: %s\n",
            my_list->node_type, my_list->pre_arg, my_list->next_arg);
        my_list = my_list->next;
    }
}
