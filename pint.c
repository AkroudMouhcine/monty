#include "monty.h"

/**
 * pint - print the value of the top of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		free(cmd.opcode);
		free(cmd.value);
		fclose(cmd.file);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
