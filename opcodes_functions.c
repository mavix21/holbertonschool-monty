#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int arg;

	if (arg_str == NULL || !is_numeric(arg_str))
	{
		free_stack(stack);
		panic("usage: push integer", line_number);
	}

	arg = atoi(arg_str);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = arg;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	if (*stack == NULL)
		return;

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		panic("can't pint, stack empty", line_number);
	}

	printf("%d\n", (*stack)->n);

	return;
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element;

	if (*stack == NULL)
	{
		panic("can't pop an empty stack", line_number);
	}

	top_element = *stack;
	*stack = top_element->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
		top_element->next = NULL;
	}

	free(top_element);
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top_next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		panic("can't swap, stack too short", line_number);
	}

	top_next = (*stack)->next;
	(*stack)->next = top_next->next;
	(*stack)->prev = top_next;
	top_next->prev = NULL;
	if (top_next->next != NULL)
		(top_next->next)->prev = *stack;
	top_next->next = *stack;

	*stack = top_next;
}
