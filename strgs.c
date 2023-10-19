#include "monty.h"
/**
 * print_char-this is the main function
 * it rints the Ascii value of chars
 * @head: the p to the p of the head of stack
 * @line_no: line number in opcode
 * Return:void
 */
void print_char(stack_t **head, unsigned int line_no)
{
	int ascii;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_3(11, line_no);
	ascii = (*head)->n;
	if (ascii < 0 || ascii > 127)
		err_3(10, line_no);
	printf("%c\n", ascii);
}

/**
 * print_str-this is the main function
 * It prints a string
 * @head: p to the p of the head os tack
 * Return: void
 */
void print_str(stack_t **head)
{
	int ascii;
	stack_t *temp;

	if (*head == NULL || head == NULL)
	{
		printf("\n");
		return;
	}
	temp = *head;

	while (temp)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}
