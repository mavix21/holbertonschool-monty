#include "monty.h"

void panic(char *err_msg, unsigned int line_number)
{
	fprintf(stderr, "L%u: %s\n", line_number, err_msg);
	exit(EXIT_FAILURE);
}

void free_stack_recursive(stack_t *top)
{
	if (top != NULL)
	{
		free_stack_recursive(top->next);
		free(top);
	}
}

void free_stack(stack_t **stack)
{
	free_stack_recursive(*stack);
	*stack = NULL;
}
