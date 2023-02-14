#include "monty.h"

int isNumber(char *str);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: Status Code
*/
int main(int argc, char **argv)
{
	FILE *fp;
	char buff[255];
	char *line;
	int lineNumber = 0;
	int e;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buff, 255, fp))
	{
		lineNumber++;
		line = buff;

		while (*line++)
			if (*line == '\n')
				*line = ' ';

		line = strstrip(buff);

		strtok(line, " ");

		if (strcmp(line, "push") == 0)
		{
			line = strtok(NULL, " ");
			if (isNumber(line) < 0)
			{
				fprintf(stderr, "L%i: usage: push integer\n", lineNumber);
				return (EXIT_FAILURE);
			}
			head = push_stack(&head, atoi(line));
		} else if (strcmp(line, "pall") == 0)
		{
			print_stack((const stack_t *)head);
		} else if (strcmp(line, "pint") == 0)
		{
			if (head == NULL)
			{
				fprintf(stderr, "L%i: can't pint, stack empty\n", lineNumber);
				return (EXIT_FAILURE);
			}
			printf("%i\n", head->n);
		} else if (strcmp(line, "pop") == 0)
		{
			if (pop_stack(&head) < 0)
			{
				fprintf(stderr, "L%i: can't pop an empty stack\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (strcmp(line, "swap") == 0)
		{
			if (swap_stack(&head) < 0)
			{
				fprintf(stderr, "L%i: can't swap, stack too short\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (strcmp(line, "add") == 0)
		{
			if (add_stack(&head) < 0)
			{
				fprintf(stderr, "L%i: can't add, stack too short\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (strcmp(line, "nop") == 0)
		{
			continue;
		} else if (strcmp(line, "sub") == 0)
		{
			if (sub_stack(&head) < 0)
			{
				fprintf(stderr, "L%i: can't sub, stack too short\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (strcmp(line, "div") == 0)
		{
			e = div_stack(&head);
			if (e < -1)
			{
				fprintf(stderr, "L%i: division by zero\n", lineNumber);
				return (EXIT_FAILURE);
			} else if (e < 0)
			{
				fprintf(stderr, "L%i: can't div, stack too short\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (strcmp(line, "mul") == 0)
		{
			if (mul_stack(&head) < 0)
			{
				fprintf(stderr, "L%i: can't mul, stack too short\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (strcmp(line, "mod") == 0)
		{
			e = mod_stack(&head);
			if (e < -1)
			{
				fprintf(stderr, "L%i: division by zero\n", lineNumber);
				return (EXIT_FAILURE);
			} else if (e < 0)
			{
				fprintf(stderr, "L%i: can't mod, stack too short\n", lineNumber);
				return (EXIT_FAILURE);
			}
		} else if (line[0] == '#')
		{
			continue;
		} else if (strcmp(line, "pchar") == 0)
		{
			if (head == NULL)
			{
				fprintf(stderr, "L%i: can't pchar, stack empty\n", lineNumber);
				return (EXIT_FAILURE);
			} else if (head->n > 127 || head->n < 0)
			{
				fprintf(stderr, "L%i: can't pchar, value out of range\n", lineNumber);
				return (EXIT_FAILURE);
			}

			putchar(head->n);
			putchar('\n');
		} else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", lineNumber, line);
			return (EXIT_FAILURE);
		}
	}

	fclose(fp);
	free_stack(head);
	head = NULL;

	return (EXIT_SUCCESS);
}

/**
 * isNumber - Check if a string contains only digits
 * @str: String to be checked
 *
 * Return: 0 if contains only digits and -1 if it does not
*/
int isNumber(char *str)
{
	int i;

	for (i = 0; str[i]!= '\0'; i++)
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
			return (-1);

	return (0);
}
