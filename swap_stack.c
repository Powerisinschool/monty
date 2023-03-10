#include "monty.h"

/**
 * swap_stack - Swap the top two elements at the top of the stack
 * @head: Stack to swap from
 *
 * Return: 0 on success
*/
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
