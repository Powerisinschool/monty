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
		if (str[i] < '0' || str[i] > '9')
			return (-1);

	return (0);
}
