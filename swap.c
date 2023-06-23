#include "monty.h"

/**
 * swap - removes the top element of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		free(cmd.opcode);
		free(cmd.value);
		fclose(cmd.file);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
