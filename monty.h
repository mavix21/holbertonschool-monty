#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char *arg_str;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void exec_opcode(char *opcode, stack_t **stack, unsigned int line_number);

/* Opcodes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);
void pchar_stack(stack_t **stack, unsigned int line_number);
void pstr_stack(stack_t **stack, unsigned int line_number);

/* Helpers */
void panic(char *err_msg, unsigned int line_number);
void free_stack(stack_t **stack);
void free_stack_recursive(stack_t *top);
int is_numeric(char *s);

#endif /* end of MONTY_H*/
