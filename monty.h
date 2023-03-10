#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

size_t print_stack(const stack_t *h);
stack_t *push_stack(stack_t **head, const int num);
char *strstrip(char *s);
void free_stack(stack_t *head);
int pop_stack(stack_t **head);
int swap_stack(stack_t **head);
int add_stack(stack_t **head);
int sub_stack(stack_t **head);
int div_stack(stack_t **head);
int mul_stack(stack_t **head);
int mod_stack(stack_t **head);
int pstr_stack(const stack_t *h);
void reverse_stack(stack_t **stack);
void rotate_stack(stack_t **head);

#endif /* MONTY_H */
