#include "monty.h"

 /**
 * exec_opcode - run opcode
 * @opcode: functions
 * @stack: structure of stack
 * @line_number: number of lines read
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
