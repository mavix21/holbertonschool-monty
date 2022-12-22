#include "monty.h"

char *arg_str = NULL;

int main(int argc, char *argv[])
{
    char buf[1024] = {0};
    FILE *fp = NULL;
    char *opcode = NULL;
    int line_number;
    stack_t *stack = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    line_number = 1;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        opcode = strtok(buf, " \n");
        if (opcode == NULL)
        {
            line_number++;
            continue;
        }
        arg_str = strtok(NULL, " \n");
        exec_opcode(opcode, &stack, line_number);
        line_number++;
    }

    fclose(fp);
    free_stack(&stack);

    return (EXIT_SUCCESS);
}
