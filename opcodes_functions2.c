#include "monty.h"

/**
 * add - adds top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */

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

/**
 * sub - subtracts top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
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
	new_node->n = (top->next)->n - top->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	free_stack(&top);
}

/**
 * nop - literally does nothing
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * div_stack - divides the second top element of the stack by
 * the top element of the stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
		panic("can't div, stack too short", line_number);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n == 0)
		panic("division by zero", line_number);

	new_node->n = (top->next)->n / top->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	free_stack(&top);
}

/**
 * mul_stack - multiplies the second top element of the stack by
 * the top element of the stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
		panic("can't mul, stack too short", line_number);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top = *stack;
	new_node->n = (top->next)->n * top->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	free_stack(&top);
}
