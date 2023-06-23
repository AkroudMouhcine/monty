#include "monty.h"

/**
 * _div -  divides the second top element of the stack by
 * the top element of the stack.
 * from the second top element of the stack.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n != 0)
		{
			(*stack)->next->n /= (*stack)->n;
			pop(stack, line_number);
			return;
		}
		else
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			goto _free_;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		goto _free_;
	}
_free_:
	free(cmd.opcode);
	free(cmd.value);
	fclose(cmd.file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
