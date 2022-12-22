#include "monty.h"

void exec_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", push},
        {"pint", push},
        {"pop", push},
        {"swap", push},
        {"add", push},
        {"sub", push},
        {"nop", push},
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
