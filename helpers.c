#include "monty.h"

/**
 * panic - closes the monty file, frees stack, prints given error
 * message and exits with the status EXIT_FAILURE
 * @err_msg: pointer to print  menssage error
 * @line_number: line to read
 */
void panic(char *err_msg, stack_t **stack, unsigned int line_number)
{
	free_stack(stack);
	fclose(info.fp);
	fprintf(stderr, "L%u: %s\n", line_number, err_msg);
	exit(EXIT_FAILURE);
}

/**
 * free_stack_recursive - checks if memory freed stack recursive
 * @top: pointer to structure
 */
void free_stack_recursive(stack_t *top)
{
	if (top != NULL)
	{
		free_stack_recursive(top->next);
		free(top);
	}
}

/**
 * free_stack - checks if memory freed stack
 * @stack: structure of stack
 */
void free_stack(stack_t **stack)
{
	free_stack_recursive(*stack);
	*stack = NULL;
}

/**
 * is_numeric - checks if a string is a number
 * @s: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
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
