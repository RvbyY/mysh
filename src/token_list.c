/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** token_list
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

list_t *add_node(list_t *head, element_t *data)
{
    list_t *copy = malloc(sizeof(list_t));

    if (!head || !copy)
        return NULL;
    copy->node_type = data->token.type;
    copy->pre_arg = my_strdup(data->pre_arg);
    copy->next_arg = my_strdup(data->next_arg);
    copy->next = head;
    return copy;
}

list_t *token_list(element_t **token_array)
{
    list_t *head = malloc(sizeof(list_t));

    if (!token_array)
        return NULL;
    head->node_type = token_array[0]->token.type;
    head->next_arg = my_strdup(token_array[0]->next_arg);
    head->pre_arg = my_strdup(token_array[0]->pre_arg);
    head->next = NULL;
    for (int i = 1; token_array[i] != NULL; i++)
        head = add_node(head, token_array[i]);
    return head;
}
