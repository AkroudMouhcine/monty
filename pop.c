#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack)
	{
		*stack = top->next;
		free(top);
	}
	else
	{
		free(cmd.opcode);
		free(cmd.value);
		fclose(cmd.file);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
