/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** token_sort
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

element_t **token_cmp(element_t **manage, int i, int j)
{
    element_t *temp;

    if (!manage)
        return NULL;
    if (manage[j]->token.type > manage[i]->token.type) {
        temp = manage[i];
        manage[i] = manage[j];
        manage[j] = temp;
    }
    return manage;
}

int token_sort(element_t **array, env_t *env)
{
    list_t *my_list;
    list_t *copy_list;

    if (!array)
        return 84;
    for (int i = 0; array[i] != NULL; i++)
        for (int j = i + 1; array[j] != NULL; j++)
            array = token_cmp(array, i, j);
    my_list = token_list(array);
    copy_list = my_list;
    while (copy_list != NULL) {
        token_to_function(copy_list, env);
        copy_list = copy_list->next;
    }
    free_struct_array(array);
    free_struct_list(my_list);
    free_struct_list(copy_list);
    return 0;
}
