#include "monty.h"

/**
 * push_f - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push_f(stack_t **stack, unsigned int line_number)
{
	int arg;

	if (info.arg_str == NULL || !is_numeric(info.arg_str))
		panic("usage: push integer", stack, line_number);

	arg = atoi(info.arg_str);

	if (info.data_format == LIFO)
		add_stack(stack, arg);
	else /* FIFO */
		add_queue(stack, arg);
}

/**
 * pall_f - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall_f(stack_t **stack, unsigned int line_number)
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

/**
 * pint_f - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		panic("can't pint, stack empty", stack, line_number);

	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element;

	if (*stack == NULL)
		panic("can't pop an empty stack", stack, line_number);

	top_element = *stack;
	*stack = top_element->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
		top_element->next = NULL;
	}

	free(top_element);
}

/**
 * swap_f - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void swap_f(stack_t **stack, unsigned int line_number)
{
	stack_t *top_next;

	if (*stack == NULL || (*stack)->next == NULL)
		panic("can't swap, stack too short", stack, line_number);

	top_next = (*stack)->next;
	(*stack)->next = top_next->next;
	(*stack)->prev = top_next;
	top_next->prev = NULL;
	if (top_next->next != NULL)
		(top_next->next)->prev = *stack;
	top_next->next = *stack;

	*stack = top_next;
}
