#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIFO 0
#define FIFO 1

/**
 * struct info_s - program info structure
 * @arg_str: element to be added to the data structure
 * @fp: file pointer to monty file
 * @data_format: LIFO or FIFO
 */
typedef struct info_s
{
	char *arg_str;
	FILE *fp;
	int data_format;
} info_t;

extern info_t info;

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
void push_f(stack_t **stack, unsigned int line_number);
void pall_f(stack_t **stack, unsigned int line_number);
void pint_f(stack_t **stack, unsigned int line_number);
void pop_f(stack_t **stack, unsigned int line_number);
void swap_f(stack_t **stack, unsigned int line_number);
void add_f(stack_t **stack, unsigned int line_number);
void sub_f(stack_t **stack, unsigned int line_number);
void nop_f(stack_t **stack, unsigned int line_number);
void div_f(stack_t **stack, unsigned int line_number);
void mul_f(stack_t **stack, unsigned int line_number);
void mod_f(stack_t **stack, unsigned int line_number);
void pchar_f(stack_t **stack, unsigned int line_number);
void pstr_f(stack_t **stack, unsigned int line_number);
void rotl_f(stack_t **stack, unsigned int line_number);
void rotr_f(stack_t **stack, unsigned int line_number);
void stack_f(stack_t **stack, unsigned int line_number);
void queue_f(stack_t **stack, unsigned int line_number);

/* Helpers */
void panic(char *err_msg, stack_t **stack, unsigned int line_number);
void panic_malloc(stack_t **stack);
void free_stack(stack_t **stack);
void free_stack_recursive(stack_t *top);
int is_numeric(char *s);

/* Double Linked List functions */
void add_stack(stack_t **stack, int n);
void add_queue(stack_t **stack, int n);

#endif /* end of MONTY_H*/
