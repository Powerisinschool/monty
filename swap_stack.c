#include "monty.h"

int swap_stack(stack_t **head)
{
    stack_t *tmp;

    if (*head == NULL || (*head)->next == NULL)
        return (-1);

    tmp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    tmp->next = (*head)->next;
    tmp->prev = *head;
    (*head)->next = tmp;

    return (0);
}
