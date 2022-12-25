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
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{"add", add_f},
		{"sub", sub_f},
		{"nop", nop_f},
		{"div", div_f},
		{"mul", mul_f},
		{"mod", mod_f},
		{"pchar", pchar_f},
		{"pstr", pstr_f},
		{"rotl", rotl_f},
		{"rotr", rotr_f},
		{"stack", stack_f},
		{"queue", queue_f},
		{NULL, NULL}
	};
	int i;
	char err_msg[256] = {0};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (!strcmp(opcode, opcodes[i].opcode))
		{
			opcodes[i].f(stack, line_number);
			break;
		}
	}

	snprintf(err_msg, sizeof(err_msg), "%s %s", "unknown instruction", opcode);
	if (opcodes[i].opcode == NULL)
		panic(err_msg, stack, line_number);
}
