#include "monty.h"

/**
 * sub -subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		free(cmd.opcode);
		free(cmd.value);
		fclose(cmd.file);
		free_stack(stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
