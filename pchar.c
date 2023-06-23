#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: stack input
 * @line_number: int input
 * Return: void.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int _char;
	if (*stack)
	{
		_char = (*stack)->n + '0';
		if (_char >= -128 && _char <= 127)
		{

			printf("%c\n", (*stack)->n);
			return;
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			goto _free_;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		goto _free_;
	}
_free_:
	free(cmd.opcode);
	free(cmd.value);
	fclose(cmd.file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
