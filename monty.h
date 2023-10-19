#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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

void err(int error_code, ...);
void err_2(int error_code, ...);
void err_3(int error_code, ...);
void open_file(char *file_name);
void call_func(op_func, char *op, char *val, int ln, int format);
void find_func(char *opcode, char *value, int ln, int format);
int parse_line(char *buffer, int line_no, int format);
void read_file(FILE *fd);
void add_nodes(stack_t **head, unsigned int line_no);
void sub_nodes(stack_t **head, unsigned int line_no);
void div_nodes(stack_t **head, unsigned int line_no);
void swap_nodes(stack_t **head, unsigned int line_no);
void mul_nodes(stack_t *head, unsigned int line_no);
void pall(const stack_t *head);
void nop(stack_t **head, unsigned int idx);
void pop(stack_t **head, unsigned int line_no);
void pint(stack_t **head, unsigned int line_no);
void free_stack(stack_t *head);
void push(stack_t **new_node);
void newhead(stack_t **head, int n);
stack_t *create_node(int n);
void mod_nodes(stack_t **head, unsigned int line_no);
void print_char(stack_t **head, unsigned int line_no);
void print_str(stack_t **head);
void queue(stack_t **new_node);

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

#endif
