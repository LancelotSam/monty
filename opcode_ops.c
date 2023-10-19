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
	int sum;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_2(8, line_no, "add");
	(*head) = (*head)->next;
	sum = (*head)->n + (*head)->prev->n;
	(*head)->n = sum;
	free((*head)->prev);
	(*head)->prev = NULL;
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
	int diff;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_2(8, line_no, "sub");
	(*head) = (*head)->next;
	diff = (*head)->n - (*head)->prev->n;
	*(head)->n = diff;
	free((*head)->prev);
	(*head)->prev = NULL;
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
	int div;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_2(8, line_no, "div");
	if ((*head)->n == 0)
		err_3(9, line_no);
	(*head) = (*head)->next;
	div = (*head)->n / (*head)->prev->n;
	(*head)->n = div;
	free((*head)->prev);
	(*head)->prev = NULL;
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
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_2(8, line_no, "swap");
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	if (tmp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
}

/**
 * mul_nodes-this is the main function
 * it multiplies nodes
 * @head: point to the pointer of tteh head
 * @line_no: line number on the opcode
 * Return:void
 */
void mul_nodes(stack_t *head, unsigned int line_no)
{
	int prod;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_2(8, line_no, "mul");
	(*head) = (*head)->next;
	prod = (*head)->n * (*head)->prev->n;
	(*head)->n = prod;
	free((*head)->prev);
	(*head)->prev = NULL;
}
