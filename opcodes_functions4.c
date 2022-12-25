#include "monty.h"
/**
 * stack_f - sets the format of the data to a stack (LIFO)
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void stack_f(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	info.data_format = FIFO;
}

/**
 * queue_f - sets the format of the data to a queue (FIFO)
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void queue_f(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	info.data_format = FIFO;
}
