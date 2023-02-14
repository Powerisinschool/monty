#include "monty.h"

void rotate_stack(stack_t **head)
{
    stack_t *curr = *head;
    stack_t *last = *head;

    if (!head || !*head)
        return;

    *head = (*head)->next;
    (*head)->prev = NULL;

    while (last->next != NULL)
        last = last->next;

    last->next = curr;
    curr->prev = last;
    curr->next = NULL;
}
