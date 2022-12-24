#include "monty.h"

/**
 * exec_opcode - run opcode
 * @opcode: functions
 * @stack: structure of stack
 * @line_number: number of lines read
 *
 * Return: Nothing
 */
void exec_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"nop", nop},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (!strcmp(opcode, opcodes[i].opcode))
		{
			opcodes[i].f(stack, line_number);
			break;
		}
	}

	if (opcodes[i].opcode == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
