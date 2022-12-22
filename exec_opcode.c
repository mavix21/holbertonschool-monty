#include "monty.h"

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
}
