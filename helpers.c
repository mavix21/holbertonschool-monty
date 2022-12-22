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

int is_numeric(char *s)
{
	if (s == NULL || strlen(s) == 0)
		return (0);

	if (*s == '-' && *(s + 1) != '\0')
		s++;

	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
		{
			return (0);
		}
		s++;
	}

	return (1);
}
