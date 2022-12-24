#include "monty.h"

/**
 * mod_stack - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
		panic("can't mod, stack too short", line_number);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n == 0)
		panic("division by zero", line_number);

	new_node->n = (top->next)->n % top->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	free_stack(&top);
}

/**
 * pchar_stack - prints the char at the top of the stack, followed
 * by a new line
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pchar_stack(stack_t **stack, unsigned int line_number)
{
	char top_char;

	if (*stack == NULL)
		panic("can't pchar, stack empty", line_number);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		panic("can't pchar, value out of range", line_number);

	top_char = (*stack)->n;

	printf("%c\n", top_char);
}