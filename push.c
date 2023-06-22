#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)stack;
	if (cmd.value && isNumber(cmd.value))
	{

		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: Can't malloc\n");
			exit(EXIT_FAILURE);
		}
		new->n = atoi(cmd.value);
		new->prev = NULL;
		if (*stack != NULL)
		{
			(*stack)->prev = new;
			new->next = *stack;
		}
		else
		{
			new->next = NULL;
		}
		*stack = new;
	}
	else
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
