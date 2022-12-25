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
		panic("can't mod, stack too short", stack, line_number);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		panic_malloc(stack);

	top = *stack;
	if (top->n == 0)
		panic("division by zero", stack, line_number);

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
		panic("can't pchar, stack empty", stack, line_number);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		panic("can't pchar, value out of range", stack, line_number);

	top_char = (*stack)->n;

	printf("%c\n", top_char);
}

/**
 * pstr_stack - prints the string starting at the top of the stack
 * followed by a new line
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	top = *stack;
	while (top != NULL)
	{
		if (top->n <= 0 || top->n > 127)
		{
			printf("\n");
			return;
		}

		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}

/**
 * rotl_stack - rotates the stack to the top, i.e the top element
 * of the stack becomes the last one, and the second top element
 * of the stack becomes the first one
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *top;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	top->prev = last;
	(top->next)->prev = NULL;
	*stack = top->next;
	top->next = NULL;
	last->next = top;
}
