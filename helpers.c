#include "monty.h"

/**
 * _split - split str to cmd and value
 * @str: string input
 * @cmd: string prointer input
 * @value: string prointer input
 * Return: void.
 */

void _split(const char *str, char **cmd, char **value)
{
	char *token;
	char *copy = malloc(strlen(str) + 1);

	if (copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(copy, str);

	token = strtok(copy, " \n\t");
	if (token != NULL)
	{
		*cmd = malloc(strlen(token) + 1);
		if (*cmd == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(*cmd, token);
		token = strtok(NULL, " \n\t");
		if (token != NULL)
		{
			*value = malloc(strlen(token) + 1);
			if (*value == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			strcpy(*value, token);
		}
		else
			*value = NULL;
	}
	else
	{
		*cmd = NULL;
		*value = NULL;
	}
	free(copy);
}
/**
 * isNumber - chechs if str is a number
 * @str: string input
 * Return: 1 if str is a number else 0
 */
int isNumber(char *str)
{
	int r = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			continue;
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			r = 1;
		else
		{
			r = 0;
			break;
		}
	}
	return (r);
}

/**
 * free_stack - free stack
 * @stack: stack to free
 * Return: void.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	*stack = NULL;
}

/**
 * run - run the opcode
 * @stack: stack
 * @len: int input
 * Return: void.
 */
void run(stack_t **stack, int len)
{
	instruction_t insts[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}};
	int i = 0;

	if (cmd.opcode[0] == '#')
		return;
	while (insts[i].opcode)
	{
		if (strcmp(insts[i].opcode, cmd.opcode) == 0)
		{
			insts[i].f(stack, len);
			break;
		}
		i++;
	}

	if (cmd.opcode && insts[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", len, cmd.opcode);
		free(cmd.opcode);
		free(cmd.value);
		free_stack(stack);
		fclose(cmd.file);
		exit(EXIT_FAILURE);
	}
}
