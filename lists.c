#include "monty.h"

/**
 * add_stack - add an element to the begining of the stack
 * @stack: address of pointer to the stack
 * @n: data to be added
 */
void add_stack(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		panic_malloc(stack);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * add_queue - add an element to the end of the stack
 * @stack: address of pointer to the stack
 * @n: data to be added
 */
void add_queue(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		panic_malloc(stack);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
