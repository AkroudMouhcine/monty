#include "monty.h"
cmd_t cmd;
/**
 * main - Interpreter for Monty ByteCodes files.
 * @argc: input size of @argv
 * @argv: input array of command line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char line[MAX_LINE_LENGTH];
	int nline = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		_split(line, &cmd.opcode, &cmd.value);
		if (cmd.opcode)
			run(&stack, ++nline);
		free(cmd.opcode);
		free(cmd.value);
	}
	free_stack(&stack);
	fclose(file);
	return (0);
}
