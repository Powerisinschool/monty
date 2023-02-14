#include "monty.h"

/**
 * sub_stack - Subtract the top element from the second at the top of the stack
 * @head: Stack to subtract from
 *
 * Return: 0 on success
*/
int sub_stack(stack_t **head)
{
    stack_t *tmp;

    if (*head == NULL || (*head)->next == NULL)
        return (-1);

    tmp = *head;
    *head = (*head)->next;
    (*head)->n -= tmp->n;
    (*head)->prev = NULL;
    free(tmp);

    return (0);
}
