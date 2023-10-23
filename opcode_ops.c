#include "monty.h"
/**
 * add_nodes-this is the main function
 * it adds nodes
 * @head: this is a pointer to the pointer of the head of teh stack
 * @line_no: the line number in the opcode
 * Return:void
 */
void add_nodes(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
/**
 * sub_nodes-this is the main function
 * it subtracts the top wo elements on tthe stack
 * @head:the ponter to the pointer of the head of the stack
 * @line_no: the line number of tthe opcode
 * Return: void
 */
void sub_nodes(stack_t **head, unsigned int line_no)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
	free(aux);
}
/**
 * div_nodes-this is the main function
 * It divides nodes
 * @head: the p to the p to the head
 * @line_no: the line number in op_code
 * Return:void
 */
void div_nodes(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
/**
 * swap_nodes-this is the main function
 * It swaps nodes
 * @head:point to the pointer of the head
 * @line_no: line number in the opcodei
 * Return:void
 */
void swap_nodes(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}

/**
 * mul_nodes-this is the main function
 * it multiplies nodes
 * @head: point to the pointer of tteh head
 * @line_no: line number on the opcode
 * Return:void
 */
void mul_nodes(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
