#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
		panic("can't add, stack too short", line_number);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top = *stack;
	new_node->n = top->n + (top->next)->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	free_stack(&top);
}

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
		panic("can't sub, stack too short", line_number);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top = *stack;
	new_node->n =(top->next)->n - top->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	free_stack(&top);
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
