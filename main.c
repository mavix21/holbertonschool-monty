#include "monty.h"

info_t info = { NULL, NULL, LIFO };

/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char buf[1024] = {0};
	FILE *fp = NULL;
	char *opcode = NULL;
	int line_number;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	info.fp = fp;

	line_number = 1;
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		opcode = strtok(buf, " \n");
		if (opcode == NULL || *opcode == '#')
		{
			line_number++;
			continue;
		}
		info.arg_str = strtok(NULL, " \n");
		exec_opcode(opcode, &stack, line_number);
		line_number++;
	}
	fclose(fp);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
